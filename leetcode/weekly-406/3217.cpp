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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> st(nums.begin(), nums.end());
    vector<ListNode*> nodes;
    for (auto p = head; p != nullptr; p = p->next) {
      if (st.count(p->val) == 0) {
        nodes.push_back(p);
      }
    }
    if (nodes.empty()) {
      return nullptr;
    }
    nodes.back()->next = nullptr;
    for (int i = (int)nodes.size() - 2; i >= 0; --i) {
      nodes[i]->next = nodes[i + 1];
    }
    return nodes.front();
  }
};
