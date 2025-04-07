#include <stdio.h>
#include <stdlib.h>

// 定义枚举类型来表示指针类型：Link 表示普通孩子指针，Thread 表示线索指针
typedef enum { LINK, THREAD } PointerTag;

// 定义线索二叉树的节点结构
typedef struct ThreadNode {
    char data;
    struct ThreadNode *left, *right;
    PointerTag ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL; // 用于记录前驱节点

// 创建一个简单的二叉树，先序输入（例如输入 AB##C##）
ThreadTree CreateTree() {
    char ch;
    scanf(" %c", &ch);
    if (ch == '#') return NULL;

    ThreadTree T = (ThreadTree)malloc(sizeof(ThreadNode));
    T->data = ch;
    T->ltag = LINK;
    T->rtag = LINK;

    T->left = CreateTree();
    T->right = CreateTree();

    return T;
}

// 中序线索化
void InThreading(ThreadTree T) {
    if (T) {
        InThreading(T->left); // 递归左子树

        if (T->left == NULL) {
            T->ltag = THREAD;
            T->left = pre;
        }

        if (pre && pre->right == NULL) {
            pre->rtag = THREAD;
            pre->right = T;
        }

        pre = T;
        InThreading(T->right); // 递归右子树
    }
}

// 创建中序线索二叉树
ThreadTree CreateInThreadTree(ThreadTree T) {
    ThreadTree head = (ThreadTree)malloc(sizeof(ThreadNode));
    head->ltag = LINK;
    head->rtag = THREAD;
    head->right = head;

    if (!T) {
        head->left = head;
    } else {
        head->left = T;
        pre = head;
        InThreading(T);
        pre->right = head;
        pre->rtag = THREAD;
        head->right = pre;
    }
    return head;
}

// 中序遍历（利用线索）
void InOrderTraverse_Thread(ThreadTree head) {
    ThreadTree p = head->left;
    while (p != head) {
        // 找到最左下的节点
        while (p->ltag == LINK)
            p = p->left;

        printf("%c ", p->data);

        // 根据线索找后继
        while (p->rtag == THREAD && p->right != head) {
            p = p->right;
            printf("%c ", p->data);
        }
        p = p->right;
    }
}

// 主函数
int main() {
    printf("请输入二叉树（前序，空节点用#):\n");
    ThreadTree T = CreateTree();
    ThreadTree threadedTree = CreateInThreadTree(T);

    printf("中序遍历结果（线索）：\n");
    InOrderTraverse_Thread(threadedTree);

    return 0;
}
