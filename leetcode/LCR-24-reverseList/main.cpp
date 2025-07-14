
#include <algorithm>
#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        stack<ListNode*> q;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            q.push(curr);
        }
        ListNode* newhead =q.top();
        q.pop();
        ListNode* cur = newhead;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
        }

        cur->next = nullptr;
        return newhead;
    }
};
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
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

class Solution3 {
    public:
    ListNode* create(int n) {
        if (n <=0) return nullptr;
        int i = 1;
        ListNode* cur;
        ListNode* head = new ListNode(i++);
        if (head == nullptr) return head;
        cur = head;
        while (i <= n) {
            cur->next = new ListNode(i++);
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }
};


int main() {
    ListNode* list = create(1);
    for (int i = 2; i <= 3; i++) {
        add_node(list, i);
    }
    Solution2 s;
    ListNode* newHead =  s.reverseList(list);
    Solution3 s2;
    ListNode* h = s2.create(1);

    cout << "finished" << std::endl;
    return 0;
}