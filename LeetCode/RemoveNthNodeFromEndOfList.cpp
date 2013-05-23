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
    int getLength(ListNode *head) {
        int ans = 0;
        while (head) {
            ans ++;
            head = head->next;
        }
        return ans;
    }
    
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = getLength(head);
        if (len == n) return head->next; //remove the head node...
        
        ListNode *tail = head;
        while (--len > n) {
            tail = tail->next;
        }

        tail->next = tail->next->next;
        
        return head; //return head, not return tail...
    }
    
    ListNode *removeNthFromEnd2(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *h = head, *t = head->next; //t should go one more step at first
        
        while (t && n) { //Or (t && n--)  but (n-- && t) is not correct...
            n --;
            t = t->next;
        }
        
        while (t) {
            t = t->next;
            h = h->next;
        }
        
        if (n && h == head) return head->next;
        
        h->next = h->next->next;
        return head;
    }
};
