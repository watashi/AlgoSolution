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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        
        if (!root) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        bool isLeftToRight = false;
        
        while (!q.empty()) {
            isLeftToRight = !isLeftToRight;
            
            TreeNode *last = q.back();
            vector<int> ret;
            
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                ret.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
                if (node == last) break;
            }
            
            if (!isLeftToRight) reverse(ret.begin(), ret.end());
            ans.push_back(ret);
        }
        
        return ans;
    }
};