#include <iostream>
#include <unordered_set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> nodes;
		for (ListNode *node = headA; node != nullptr; node = node->next) {
			nodes.insert(node);
		}
		for (ListNode *node = headB; node != nullptr; node = node->next) {
			if (nodes.find(node) != nodes.end()) {
				return node;
			}
		}
		return nullptr;
	}
};

int main() {



	return 0;
}