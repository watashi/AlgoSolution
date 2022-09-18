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
  vector<int> v;

  TreeNode* reverseOddLevels(TreeNode* root) {
    vector<TreeNode*> v;
    queue<const TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p != nullptr) {
        v.push_back(new TreeNode(p->val));
        q.push(p->left);
        q.push(p->right);
      }
    }

    int start = 0, width = 1;
    for (int i = 0; start + width <= (int)v.size(); ++i, start += width, width *= 2) {
      if (i % 2 != 0) {
        reverse(v.data() + start, v.data() + start + width);
      }
    }
    for (int i = 0; i < (int)v.size(); ++i) {
      int il = i * 2 + 1;
      int ir = il + 1;
      if (il < (int)v.size()) {
        v[i]->left = v[il];
      }
      if (ir < (int)v.size()) {
        v[i]->right = v[ir];
      }
    }
    return v[0];
  }
};
