
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
  vector<int> h;

  pair<int, int> height(TreeNode* root) {
    pair<int, int> ret(-1, root->val);
    for (auto child : { root->left, root->right }) {
      if (child != nullptr) {
        ret = max(ret, height(child));
      }
    }
    ++ret.first;
    if (h.size() <= root->val) {
      h.resize(root->val + 1);
    }
    h[root->val] = ret.first;
    return ret;
  }

  bool dfs(TreeNode* root, int leaf, vector<const TreeNode*>& path) {
    if (root == nullptr) {
      return false;
    }
    else {
      auto ret = root->val == leaf || dfs(root->left, leaf, path) || dfs(root->right, leaf, path);
      if (ret) {
        path.push_back(root);
      }
      return ret;
    }
  }

  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    auto hh = height(root);
    // cout << hh.first << "," << hh.second << endl;
    vector<const TreeNode*> path;
    dfs(root, hh.second, path);
    reverse(path.begin(), path.end());

    map<int, int> m;
    int h2 = 0;
    for (int i = 1; i < (int)path.size(); ++i) {
      auto p = path[i - 1], c = path[i];
      h2 = max(h2, i - 1);
      for (auto cc : { p->left, p->right }) {
        if (cc != nullptr && cc != c) {
          h2 = max(h2, i + h[cc->val]);
          // cout << "??? " << cc->val << " @ " << h[cc->val] << " + " << i << endl;
        }
      }
      m[c->val] = h2;
      // cout << c->val << " => " << h2 << endl;
    }

    vector<int> ret;
    for (int i : queries) {
      auto it = m.find(i);
      if (it == m.end()) {
        ret.push_back(hh.first);
      }
      else {
        ret.push_back(it->second);
      }
    }
    return ret;
  }
};
