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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        if (!a) return b;
        if (!b) return a;
        
        if (a->val > b->val) return mergeTwoLists(b, a);
        
        ListNode *ans = a, *p = a;
        
        a = a->next;
        
        while (a && b) {
            if (a->val <= b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next; // Here...
        }
        
        while (a) {
            p->next = a;
            a = a->next;
            p = p->next;
        }
        
        while (b) {
            p->next = b;
            b = b->next;
            p = p->next;
        }
        
        return ans;
    }
    
    ListNode *merge(vector<ListNode *> &lists, int b, int e) {
        if (b > e) return NULL;
        if (b == e) return lists[b];
        if (b + 1 == e) {
            return mergeTwoLists(lists[b], lists[e]);
        }
        
        int p = b + (e - b) / 2;
        return mergeTwoLists(merge(lists, b, p), merge(lists, p + 1, e));
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return merge(lists, 0, lists.size() - 1);
    }
};