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
    
    // Always divide into two parts: left and mid
    ListNode *reverse(ListNode *left, ListNode *right, ListNode *tail) {
        if (left == right) return left;
      
        ListNode *mid = left->next;
        left->next = tail;
        
        while (mid!= right) {
            ListNode *tmp = mid;
            mid = mid->next;
            tmp->next = left;
            left = tmp;
        }
        
        mid->next = left;
        return mid;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *ans = new ListNode(0);
        ans->next = head;
        
        ListNode *tail = ans;
        ListNode *left = head;
        int count = 1;
        while (count < m && left) {
            tail = left;
            left = left->next;
            count ++;
        }
        
        ListNode *right = left;
        while (count < n && right) {
            right = right->next;
            count ++;
        }
        
        tail->next = reverse(left, right, right->next);
        
        return ans->next;
    }
};