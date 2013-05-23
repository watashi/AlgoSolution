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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int delta = 0;
        ListNode *ans = l1, *last = l1;
        
        while (l1 && l2) {
            l1->val += l2->val;
            l1->val += delta;
            if (l1->val > 9) {
                delta = l1->val / 10;
                l1->val %= 10;
            } else {
                delta = 0; // Always forget set delta back to 0
            }
            if (!l1->next) last = l1;  // Save the last node
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (!l1) {
            while (l2) {
                l2->val += delta;
                if (l2->val > 9) {
                    delta = l2->val / 10;
                    l2->val %= 10;
                } else {
                    delta = 0; // Always forget set delta back to 0
                }
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
            
            if (delta > 0) {
                last->next = new ListNode(delta);
            }
        } else {
            while (l1 && delta > 0) {
                l1->val += delta;
                if (l1->val > 9) {
                    delta = l1->val / 10;
                    l1->val %= 10;
                } else {
                    delta = 0; // Set delta back to 0
                }
                if (!l1->next) last = l1; // Save the last node
                l1 = l1->next;
            }
            
            if (delta > 0) {
                last->next = new ListNode(delta);
            }
        }
        
        return ans;
        
    }
};