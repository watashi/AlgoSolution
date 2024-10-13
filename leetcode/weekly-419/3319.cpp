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

  int gao(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    else {
      int l = gao(root->left);
      int r = gao(root->right);
      if (l >= 0 && r >= 0 && l == r) {
        v.push_back(l + 1);
        return l + 1;
      }
      else {
        return -1;
      }
    }
  }

  int kthLargestPerfectSubtree(TreeNode* root, int k) {
    v.clear();
    gao(root);
    sort(v.rbegin(), v.rend());
    if (k <= v.size()) {
      return (1 << v[k - 1]) - 1;
    }
    else {
      return -1;
    }
  }
};
