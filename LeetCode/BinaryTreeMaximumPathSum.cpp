/**
  Given a binary tree, find the maximum path sum.

  The path may start and end at any node in the tree.

  For example:
  Given the below binary tree,

         1
        / \
       2   3
  Return 6.
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
    map<TreeNode*, int> sumMap;
    int ans, maxSum;
    
    int maxRootToLeafSum(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            sumMap[root] = root->val;
            return root->val;
        }
        
        int maxLeft = maxRootToLeafSum(root->left);
        int maxRight = maxRootToLeafSum(root->right);
        
        if (maxLeft < 0) sumMap[root] = max(maxRight, 0) + root->val;
        else if (maxRight < 0) sumMap[root] = max(maxLeft, 0) + root->val;
        else sumMap[root] = max(maxLeft, maxRight) + root->val;
        
        return sumMap[root];
    }
    
    void maxPathSumRecursively(TreeNode *root) {
        if (!root) return;
        
        int sum = root->val;
        ans = max(ans, sumMap[root]);  // Update ans
        
        if (root->left) {
            if (sumMap[root->left] > 0) sum += sumMap[root->left];
            ans = max(ans, sum);   // Update ans
            maxPathSumRecursively(root->left);
        }
        
        if (root->right) {
            if (sumMap[root->right] > 0) sum += sumMap[root->right];
            ans = max(ans, sum);  // Update ans
            maxPathSumRecursively(root->right);
        }
    }
    
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans = INT32_MIN;
        maxSum = INT32_MIN;
        
        if (!root) return ans;
        if (!root->left && !root->right) return root->val;
        
        sumMap.clear();
        ans = maxRootToLeafSum(root);
        
        maxPathSumRecursively(root);
        
        return ans;
    }
};