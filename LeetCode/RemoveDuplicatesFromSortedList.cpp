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
    unordered_set<int> s;
    
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!head || !head->next) return head;
        
        s.clear();
        s.insert(head->val);
        
        ListNode *node = head->next, *currentHead = head;
        while (node != NULL) {
            if (s.find(node->val) == s.end()) {
                s.insert(node->val); //don't forget to insert...
                currentHead->next = node;
                currentHead = node; //move head to the next...
            }
            
            node = node->next;
        }
        
        currentHead->next = NULL; //don't forget to set NULL... 
        
        return head;
    }
};