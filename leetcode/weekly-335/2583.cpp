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
  long long kthLargestLevelSum(TreeNode* root, int k) {
    vector<int64_t> x;
    vector<const TreeNode*> v;
    v.push_back(root);
    while (!v.empty()) {
      int64_t s = 0;
      vector<const TreeNode*> w;
      for (auto p : v) {
        s += p->val;
        if (p->left != nullptr) {
          w.push_back(p->left);
        }
        if (p->right != nullptr) {
          w.push_back(p->right);
        }
      }
      v = std::move(w);
      x.push_back(s);
    }
    sort(x.rbegin(), x.rend());
    if (k > x.size()) {
      return -1;
    }
    else {
      return x[k - 1];
    }
  }
};
