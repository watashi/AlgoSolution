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
  int minimumOperations(TreeNode* root) {
    int ret = 0;
    vector<const TreeNode*> cur;
    cur.push_back(root);
    while (!cur.empty()) {
      vector<pair<int, int>> v;
      vector<const TreeNode*> pre;
      pre.swap(cur);
      for (int i = 0; i < (int)pre.size(); ++i) {
        auto p = pre[i];
        v.emplace_back(p->val, i);
        if (p->left != nullptr) {
          cur.push_back(p->left);
        }
        if (p->right != nullptr) {
          cur.push_back(p->right);
        }
      }
      sort(v.begin(), v.end());

      int tmp = (int)v.size();
      vector<bool> mark(v.size(), false);
      for (int i = 0; i < (int)v.size(); ++i) {
        if (!mark[i]) {
          --tmp;
          while (!mark[i]) {
            mark[i] = true;
            i = v[i].second;
          }
        }
      }
      ret += tmp;

    }
    return ret;
  }
};
