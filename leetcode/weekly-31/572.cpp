/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    map<pair<int, pair<int, int>>, int> mp;
    set<int> ids;

    int getId(TreeNode* p) {
        int ret;
        if (p == nullptr) {
            ret = -1;
        } else {
            pair<int, pair<int, int>> key;
            key.first = p->val;
            key.second.first = getId(p->left);
            key.second.second = getId(p->right);
            if (mp.count(key) > 0) {
                ret = mp[key];
            } else {
                ret = mp.size();
                mp[key] = ret;
            }
            // printf("%d => %d\n", p->val, ret);
        }
        ids.emplace(ret);
        return ret;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        int tid = getId(t);
        ids.clear();
        getId(s);
        return ids.count(tid) > 0;
    }
};
