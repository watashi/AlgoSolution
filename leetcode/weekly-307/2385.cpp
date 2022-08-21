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
  struct R {
    int depth = -1;
    int ans = 0;
    int dist = -1;
  };

  R dfs(TreeNode* root, int start) {
    if (root == nullptr) {
      return R{};
    }
    else {
      auto ll = dfs(root->left, start);
      auto rr = dfs(root->right, start);
      R ret{};
      ret.depth = max(ll.depth, rr.depth) + 1;
      ret.ans = max(ll.ans, rr.ans);
      if (root->val == start) {
        ret.dist = 0;
        ret.ans = ret.depth;
      }
      else if (ll.dist >= 0) {
        ret.dist = ll.dist + 1;
        ret.ans = max(ret.ans, ll.dist + rr.depth + 2);
      }
      else if (rr.dist >= 0) {
        ret.dist = rr.dist + 1;
        ret.ans = max(ret.ans, rr.dist + ll.depth + 2);
      }
      return ret;
    }
  }

  int amountOfTime(TreeNode* root, int start) {
    return dfs(root, start).ans;
  }
};
