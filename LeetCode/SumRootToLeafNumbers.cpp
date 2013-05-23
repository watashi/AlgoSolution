/**
  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

  An example is the root-to-leaf path 1->2->3 which represents the number 123.

  Find the total sum of all root-to-leaf numbers.

  For example,

      1
     / \
    2   3
  The root-to-leaf path 1->2 represents the number 12.
  The root-to-leaf path 1->3 represents the number 13.

  Return the sum = 12 + 13 = 25.
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

    int ans = 0;
    
    void sumNumbers(TreeNode *root, int sum)
    {
        if (!root) {
            return;
        }
        
        if (!root->left && !root->right) {
            ans += sum * 10 + root->val;
            return;
        }
        
        sumNumbers(root->left, sum * 10 + root->val);
        sumNumbers(root->right, sum * 10 + root->val);

    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ans = 0;
        sumNumbers(root, 0);
        return ans; 
        
    }
};