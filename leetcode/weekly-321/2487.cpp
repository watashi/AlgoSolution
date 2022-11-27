/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* removeNodes(ListNode* head) {
    vector<ListNode*> v;
    for (auto p = head; p != nullptr; p = p->next) {
      v.push_back(p);
    }
    reverse(v.begin(), v.end());

    ListNode* h = nullptr;
    for (auto p : v) {
      if (h == nullptr || p->val >= h->val) {
        p->next = h;
        h = p;
      }
    }
    return h;
  }
};
