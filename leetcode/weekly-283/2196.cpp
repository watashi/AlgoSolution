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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> m;
        map<int, int> p;
        for (const auto& i: descriptions) {
            p[i[1]] = i[0];
            if (m.count(i[0]) == 0) {
                m[i[0]] = new TreeNode(i[0]);
            }
            if (m.count(i[1]) == 0) {
                m[i[1]] = new TreeNode(i[1]);
            }
            if (i[2] != 0) {
                m[i[0]]->left = m[i[1]];
            } else {
                m[i[0]]->right = m[i[1]];
            }
        }
        int root = p.begin()->second;
        while (p.count(root) > 0) {
            root = p[root];
        }
        return m[root];
    }
};
