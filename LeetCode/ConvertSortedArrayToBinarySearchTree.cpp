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
    TreeNode *addToTree(vector<int> &num, int b, int e) {
        if (b > e) return NULL;
        
        int mid = (b + e + 1) / 2;
        TreeNode *ret = new TreeNode(num[mid]);
        ret->left = addToTree(num, b, mid - 1);
        ret->right = addToTree(num, mid + 1, e);
        
        return ret;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return addToTree(num, 0, num.size() - 1);
    }
};