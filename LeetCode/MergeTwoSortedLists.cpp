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
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *head, *p; //Don't forget the head point, to return
        
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        
        p = head;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        while (l1) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        
        while (l2) {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
        
        return head;
    }
};