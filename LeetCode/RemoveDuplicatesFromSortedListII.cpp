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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) return head;
        
        ListNode *b = head, *e = head->next, *ans = NULL;
        
        while (e) {
            if (b->val == e->val) {
                e = e->next;
                while (e && e->val == b->val) e = e->next;
                b = e;
                if (e) e = e->next;
            } else {
                break;
            }
        }
        
        head = b, ans = b;
        
        while (e) {
            if (b->val == e->val) {
                e = e->next;
                while (e && e->val == b->val) e = e->next;
                b = e;
                if (e) e = e->next;
            } else {
                if (head != b) {  // Notice: head = head->next;
                    head->next = b;
                    head = head->next;
                }
                b->next = e;
                b = e;
                e = e->next;
            }
        }
       
        if (head != b) {  // Notice: set the last node's next value...
            head->next = b;
            if (b) b->next = NULL;
        }
        
        return ans;
    }
};