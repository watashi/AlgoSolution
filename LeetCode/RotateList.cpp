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
    int lengthOfList(ListNode *head) {
        int len = 0;
        while (head) {
            len ++;
            head = head->next;
        }
        return len;
    }
    
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) return head;
        int len = lengthOfList(head);
        k %= len;
        if (k == 0) return head;
        
        ListNode *ans, *fast = head, *slow = head;
        
        while (k --) {
            fast = fast->next;
        }
        
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        ans = slow->next;
        slow->next = NULL;
        
        return ans;
    }
};