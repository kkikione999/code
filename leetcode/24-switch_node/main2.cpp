#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode * dummy = new ListNode(0, head);
        switchnode(head, dummy);
        ListNode * newhead = dummy->next;
        delete dummy;
        return newhead;
    }

    void switchnode (ListNode* cur, ListNode* prev) {
        if (cur == nullptr || cur->next == nullptr) return;
        ListNode* next = cur->next;
        prev->next = cur->next;
        cur->next = next->next;
        next->next = cur;
        switchnode (cur->next, cur);
    }
    ListNode* swapPairs1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy->next;
        ListNode* prev = dummy;
        ListNode* next = cur->next;
        while (1) {
            prev->next = cur->next;
            cur->next = next->next;
            next->next = cur;
            if (cur->next == nullptr || cur->next->next == nullptr) break;
            prev = cur;
            cur = cur->next;
            next = cur->next;
        }
        ListNode* newhead = dummy->next;
        delete dummy;
        return newhead;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
    }


};
void add_node(ListNode* ptr, int val) {
    ListNode* cur;
    for (cur = ptr; cur->next != nullptr; cur = cur->next) {}
    ListNode* new_node = new ListNode(val,nullptr);
    cur->next = new_node;
}

ListNode* create(int val) {
    ListNode* head = new ListNode(val, nullptr);
    return head;
}

int main() {
    ListNode* list = create(1);
    for (int i = 2; i <= 3; i++) {
        add_node(list, i);
    }
    Solution s;
    s.swapPairs1(list);
    std::cout << "finished" << std::endl;

    return 0;
}