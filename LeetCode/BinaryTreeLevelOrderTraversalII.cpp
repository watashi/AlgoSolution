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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        if (!root) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode *back = q.back();
            vector<int> level;
            
            while (!q.empty()) {
                TreeNode *curr = q.front();
                q.pop();
                
                if (curr) level.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
                if (curr == back) break;
            }
            
            if (level.size() > 0) ans.push_back(level);
        }
        
        int b = 0, e = ans.size() - 1;
        while (b < e) {
            swap(ans[b ++], ans[e --]);
        }
        
        return ans;
    }
};