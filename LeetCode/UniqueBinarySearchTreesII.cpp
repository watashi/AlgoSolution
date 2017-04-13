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
    vector<TreeNode *> generateTreesDFS(int left, int right) {
        vector<TreeNode *> ret;
        
        if (left > right) {
            ret.push_back(NULL);
            return ret;
        }
        
        for (int i = left; i <= right; i ++) {
            vector<TreeNode *> leftChildren = generateTreesDFS(left, i - 1);
            vector<TreeNode *> rightChildren = generateTreesDFS(i + 1, right);
            
            for (int j = 0; j < leftChildren.size(); j ++) {
                for (int k = 0; k < rightChildren.size(); k ++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftChildren[j];
                    root->right = rightChildren[k];
                    ret.push_back(root);
                }
            }
        }
        
        return ret;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTreesDFS(1, n);
    }
};