/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static bool dfs(TreeNode *root, int value, string& path) {
        if (root->val == value) {
            return true;
        }
        if (root->left != nullptr) {
            path.push_back('L');
            if (dfs(root->left, value, path)) {
                return true;
            }
            path.pop_back();
        }
        if (root->right != nullptr) {
            path.push_back('R');
            if (dfs(root->right, value, path)) {
                return true;
            }
            path.pop_back();
        }
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        dfs(root, startValue, startPath);
        dfs(root, destValue, destPath);
        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());
        while (!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()) {
            startPath.pop_back();
            destPath.pop_back();
        }
        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());
        for (auto& c: startPath) {
            c = 'U';
        }
        return startPath + destPath;
    }
};
