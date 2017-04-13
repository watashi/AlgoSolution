/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 *
 
    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
    You may not alter the values in the nodes, only nodes itself may be changed.
    Only constant memory is allowed.

    For example,
    Given this linked list: 1->2->3->4->5
    For k = 2, you should return: 2->1->4->3->5
    For k = 3, you should return: 3->2->1->4->5
    
 */
class Solution {
public:
    ListNode *reverse(ListNode *left, ListNode *right, ListNode *tail) {
        if (left == right) return left;
      
        ListNode *mid = left->next;
        left->next = tail;
        
        while (mid != right) {
            ListNode *tmp = mid;
            mid = mid->next;
            tmp->next = left;
            left = tmp;
        }
        
        mid->next = left;
        return mid;
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ans = new ListNode(-1);
        ans->next = head;
        
        ListNode *tail = ans;
        ListNode *left = head;
      
        while (left) {
            int count = 1;
        
            ListNode *right = left;
            while (count < k && right->next) {
                right = right->next;
                count ++;
            }
        
            if (count == k) 
                tail->next = reverse(left, right, right->next);
            else break;
        
            tail = left;
            left = left->next;
        }
        
        return ans->next;
        
    }
};