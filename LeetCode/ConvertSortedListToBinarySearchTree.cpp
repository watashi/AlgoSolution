/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    
    TreeNode *getBST(ListNode * &head, int b, int e) {
        if (b > e) return NULL;
        
        int mid = (b + e + 1) / 2;
        
        TreeNode *left = getBST(head, b, mid - 1);
        
        TreeNode *root = new TreeNode(head->val);
        
        head = head->next;
        TreeNode *right = getBST(head, mid + 1, e);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height = getLength(head);
        
        return getBST(head, 0, height - 1);
    }
};