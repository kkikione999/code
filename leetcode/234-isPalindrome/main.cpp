#include <iostream>
#include <stack>
#include <vector>
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
	bool isPalindrome(ListNode* head) {
		if (head == nullptr) return false;
		if (head->next == nullptr) return true;
		int cnt = 0;
		for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
			cnt++;
		}
		ListNode* temp = head;
		stack<int> st;
		for (int i = 0; i < cnt / 2; i++) {
			st.push(temp->val);
			temp = temp->next;
		}

		if (cnt % 2 == 0) {

			for (int i = cnt / 2 + 1;i<=cnt;i++ ) {
				if (st.top() != temp->val) {
					return false;
				}
				temp = temp->next;
				st.pop();
			}
		}
		else if (cnt % 2 != 0) {
			temp = temp->next;
			for (int i = cnt / 2 + 2;i<=cnt;i++ ) {
				if (st.top() != temp->val) {
					return false;
				}
				temp = temp->next;
				st.pop();
			}

		}
		return true;
	}
};
ListNode * create_list(vector<int> tar) {
	if (tar.size() == 0) return nullptr;
	ListNode* head = new ListNode(tar[0],nullptr);
	if (head == nullptr) return nullptr;
	ListNode*temp = head;
	for (int i = 1; i < tar.size(); i++) {
		temp->next = new ListNode(tar[i]);
		temp = temp->next;
	}
	return head;
}

int main() {
	vector<int> tar({1,2,0});
	ListNode* head = create_list(tar);
	Solution test;
	bool a  = test.isPalindrome(head);
	cout << a << endl;
	return 0;
}