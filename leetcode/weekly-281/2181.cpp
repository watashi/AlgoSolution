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
    ListNode* mergeNodes(ListNode* head) {
        ListNode ret;
        ListNode* cur = &ret;
        for (auto i = head->next; i != nullptr; i = i->next) {
            int s = 0;
            while (i->val != 0) {
                s += i->val;
                i = i->next;
            }
            cur->next = new ListNode(s);
            cur = cur->next;
        }
        return ret.next;
    }
};
