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
    int ans;
    void minDepth(TreeNode *root, int depth) {
        if (!root) { //Although there is not the case
            return; 
        }
        
        if (!root->left && !root->right) { //only leaf, could be the end of the path
            ans = min(ans, depth + 1);
            return;
        }
        
        minDepth(root->left, depth + 1);
        minDepth(root->right, depth + 1);
    }
    
    void bfs(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        
        vector<TreeNode *> tmp;
        int level = 1;
        while (!q.empty()) {
            while (!q.empty()) {
                tmp.push_back(q.front());
                q.pop();
            }
            
            for (int i = 0; i < tmp.size(); i ++) {
                if (!tmp[i]->left && !tmp[i]->right) {
                    ans = min(ans, level);
                    return;
                }
                
                if (tmp[i]->left) q.push(tmp[i]->left);
                if (tmp[i]->right) q.push(tmp[i]->right);
            }
            
            level ++;
            tmp.clear(); //Don't forget to clear()!
        }
    }
    
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        ans = INT_MAX;
        minDepth(root, 0); //56 milli secs
        //bfs(root); //56 milli secs
        
        return ans;
    }
};