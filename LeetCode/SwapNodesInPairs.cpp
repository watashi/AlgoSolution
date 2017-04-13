/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!head) return head;
        
        ListNode *l = NULL, *r = NULL;
        l = head;
        
        if (l) r = head->next;
        while (r) {
            swap(l->val, r->val);
            l = r->next;
            if (l) r = l->next;
            else r = NULL;
        }
        
        return head;
    }
};