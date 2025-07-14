#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //翻转链表
    ListNode* reverse(ListNode* head){
        ListNode *first = head, *second = head->next, *third = head->next->next;
        ListNode *newHead;
        first->next = nullptr;
        while (second->next != nullptr)
        {
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        return second;
    }

    ListNode* reverse2(ListNode* node)
    {
        if (node->next == nullptr) return node;
        ListNode *last = reverse2(node->next);
        node->next->next = node;
        node->next = nullptr;
        return last;
    }
    ListNode* Back;
    ListNode* reverseN(ListNode* head, int n)
    {
        if (n == 1)
        {
            Back = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next, n - 1);

        head->next->next = head;
        head->next = Back;
        return last;

    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right <= 1 || head == nullptr || head->next == nullptr || right == left) return head;
        ListNode *dummy = new ListNode(0, head);
        if (dummy == nullptr) return dummy;
        ListNode *front, *back;
        ListNode *temp = dummy;
        for (int i = 0; temp != nullptr ; i++)
        {
            if (i == left-1) front = temp;
            if (i == right)
            {
                back = temp;
                break;
            }
            temp = temp->next;
        }
        temp = back;
        back = back->next;
        temp->next = nullptr;
        //
        front->next =  reverse2(front->next);
        temp = front->next;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = back;
        temp = dummy->next;
        delete dummy;
        return temp;
    }


};

ListNode* create(int n){
    if(n <= 0) return nullptr;
    ListNode* head = nullptr;
    ListNode* cur = new ListNode(1);
    if (cur == nullptr) return nullptr;
    head = cur;
    for(int i = 2; i <= n; i++)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    return head;
}
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp; // 释放每个节点
    }
}



int main (int argc, const char * argv[])
{
    Solution s;
    ListNode* head = create(10);
    head = s.reverseN(head,3);
    for (ListNode* it = head; it != nullptr; it = it->next)
    {
        cout << it->val << " ";
    }
    deleteList(head);
    return 0;
}