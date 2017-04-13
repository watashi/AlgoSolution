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

    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        
        if (!isSymmetric(left->left, right->right)) return false;
        return isSymmetric(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root) return true;
        
        
        return isSymmetric(root->left, root->right);
    }
};

/*

// Unaccepted solution... BFS... why?
class Solution {
public:

    bool isSymetric(const vector<TreeNode *> &level) {
        int b = 0, e = level.size() - 1;
        while (b < e) {
            if (!level[b] && !level[e]) {b ++; e --; continue;}
            if (!level[b] || !level[e]) return false;
            if (level[b ++]->val != level[e --]->val) return false; 
        }
            
        return true;
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root || (!root->left && !root->right)) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<TreeNode *> level;
        while (!q.empty()) {
            while (!q.empty()) {
                level.push_back(q.front());
                q.pop();
            }
            
            if (!isSymetric(level)) return false;
            
            for (int i = 0; i < level.size(); i ++) {
                if (level[i]) {
                    if (level[i]->left) q.push(level[i]->left);
                    else q.push(NULL);
                    if (level[i]->right) q.push(level[i]->right);
                    else q.push(NULL);
                } else {
                    q.push(NULL); 
                    q.push(NULL);
                }
                
            }
            
            level.clear();
    
        }
        
        return true;
    }
};

*/