#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树结点结构体
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 队列结构体，用于层序遍历辅助操作
typedef struct {
    TreeNode **arr;     // 存放指针数组
    int front;          // 队头
    int rear;           // 队尾
    int capacity;       // 队列容量
} Queue;

// 创建队列
Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    // 分配内存失败
    if (!q) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    // 分配存放指针的数组
    q->arr = (TreeNode**)malloc(sizeof(TreeNode*) * capacity);

    // 分配内存失败
    if (!q->arr) {
        free(q);
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    return q;
}

// 判断队列是否为空
int isQueueEmpty(Queue *q) {
    return (q->front == q->rear);
}

// 入队
void enqueue(Queue *q, TreeNode *node) {
    if (q->rear >= q->capacity) {
        fprintf(stderr, "Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    q->arr[q->rear++] = node;
}

// 出队
TreeNode* dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }
    return q->arr[q->front++];
}

// 释放队列
void destroyQueue(Queue *q) {
    if (q) {
        if (q->arr) free(q->arr);
        free(q);
    }
}

// 创建完全二叉树：采用数组辅助法建立结点链表结构
TreeNode* createCompleteBinaryTree(const char *str) {
    if (!str) return NULL;
    int len = strlen(str);
    if (len == 0) return NULL;
    
    // 先为每个字符创建结点，存放到数组中
    TreeNode **nodes = (TreeNode**)malloc(sizeof(TreeNode*) * len);
    if (!nodes) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < len; i++) {
        nodes[i] = (TreeNode*)malloc(sizeof(TreeNode));
        if (!nodes[i]) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        nodes[i]->data = str[i];
        nodes[i]->left = nodes[i]->right = NULL;
    }
    
    // 根据完全二叉树的性质建立左右子树关系
    for (int i = 0; i < len; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        if (leftIndex < len) {
            nodes[i]->left = nodes[leftIndex];
        }
        if (rightIndex < len) {
            nodes[i]->right = nodes[rightIndex];
        }
    }
    TreeNode *root = nodes[0];
    free(nodes); // 辅助数组释放
    return root;
}

// 查找结点：采用前序遍历方式
TreeNode* searchTree(TreeNode *root, char value) {
    if (root == NULL) return NULL;
    if (root->data == value)
        return root;
    TreeNode *found = searchTree(root->left, value);
    if (found)
        return found;
    return searchTree(root->right, value);
}

// 删除结点：删除值为value的第一个结点，删除时用最后一个结点数据覆盖后删除最后一个结点
// 由于需要更新树根，故参数为指向根指针的指针
int deleteNode(TreeNode **rootPtr, char value) {
    if (rootPtr == NULL || *rootPtr == NULL) return 0;
    
    TreeNode *root = *rootPtr;
    Queue *q = createQueue(100); // 假设树的最大结点数不超过100
    enqueue(q, root);
    
    TreeNode *target = NULL;      // 待删除结点
    TreeNode *last = NULL;        // 最后一个结点
    TreeNode *lastParent = NULL;  // 最后一个结点的父结点
    // 为记录父结点，采用辅助队列：入队顺序与结点队列一致
    Queue *parentQ = createQueue(100);
    enqueue(parentQ, NULL);  // 根结点没有父结点

    while (!isQueueEmpty(q)) {
        TreeNode *curr = dequeue(q);
        TreeNode *currParent = dequeue(parentQ);
        // 记录待删除结点
        if (curr->data == value && target == NULL) {
            target = curr;
        }
        // 更新最后一个结点及其父结点
        last = curr;
        lastParent = currParent;
        // 左子结点入队
        if (curr->left) {
            enqueue(q, curr->left);
            enqueue(parentQ, curr);
        }
        // 右子结点入队
        if (curr->right) {
            enqueue(q, curr->right);
            enqueue(parentQ, curr);
        }
    }
    destroyQueue(q);
    destroyQueue(parentQ);
    
    if (target == NULL) {
        // 没有找到要删除的结点
        return 0;
    }
    
    // 如果目标结点与最后结点相同，则直接删除
    if (target == last) {
        if (lastParent == NULL) {
            // 树只有一个结点
            free(last);
            *rootPtr = NULL;
        } else {
            // 判断last是左还是右子结点
            if (lastParent->left == last)
                lastParent->left = NULL;
            else
                lastParent->right = NULL;
            free(last);
        }
    } else {
        // 用最后结点的数据覆盖目标结点
        target->data = last->data;
        // 删除最后结点
        if (lastParent) {
            if (lastParent->left == last)
                lastParent->left = NULL;
            else if (lastParent->right == last)
                lastParent->right = NULL;
        }
        free(last);
    }
    
    return 1;
}

// 前序遍历：递归实现，访问顺序为 根 -> 左 -> 右
void preOrderTraversal(TreeNode *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// 销毁二叉树：递归释放每个结点
void destroyTree(TreeNode *root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

// 测试函数
int main() {
    const char *str = "ABCDEFGHYJK";
    TreeNode *root = createCompleteBinaryTree(str);
    
    printf("创建的完全二叉树（前序遍历）：\n");
    preOrderTraversal(root);
    printf("\n");
    
    // 查找结点
    char target = 'E';
    TreeNode *found = searchTree(root, target);
    if (found)
        printf("查找到字符 '%c'。\n", target);
    else
        printf("未找到字符 '%c'。\n", target);
    
    // 删除结点，删除第一个出现的 'B'
    char delVal = 'B';
    if (deleteNode(&root, delVal)) {
        printf("删除字符 '%c' 后，前序遍历结果：\n", delVal);
        preOrderTraversal(root);
        printf("\n");
    } else {
        printf("字符 '%c' 未找到，无法删除。\n", delVal);
    }
    
    // 销毁二叉树
    destroyTree(root);
    
    return 0;
}
