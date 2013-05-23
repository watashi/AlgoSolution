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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) return head;
        
        ListNode *ltHead, *gtHead, *lt = head, *gt = head;
        
        //1 3 2,,  3
        if (lt->val < x) {
            ltHead = lt;
            gt = lt->next;
            while (gt && gt->val < x) {
                lt = gt;
                gt = gt->next;
            }
            gtHead = gt;
        } else {
            gtHead = gt;
            lt = gt->next;
            while (lt && lt->val >= x) {
                gt = lt;
                lt = lt->next;
            }
            ltHead = lt;
            if (lt) gt->next = lt->next;
            else gt->next = NULL;
        }
        
        while(gt && gt->next) {
            ListNode *tmpNode = gt->next;
            
            while (tmpNode && tmpNode->val < x) { // Don't forget to check if tmpNode is NULL
                lt->next = tmpNode;
                lt = lt->next;
                tmpNode = tmpNode->next;
            }
            
            gt->next = tmpNode;
            gt = gt->next;
        }
        
        if (lt) lt->next = gtHead;
        else ltHead = gtHead;
        
        return ltHead;
        
    }
};