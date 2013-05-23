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
    int findRootIndex(const vector<int> &in, int b, int e, int target) {
        for (int i = b; i <= e; i ++) {
            if (in[i] == target) return i;
        }
        return -1;
    }
    
    TreeNode *buildRecursively(const vector<int> &p, int pb, int pe, const vector<int> &in, int ib, int ie, int count) {
        if (count <= 0) return NULL;
        
        TreeNode *root = new TreeNode(p[pb]);
        
        int rootIndex = findRootIndex(in, ib, ie, p[pb]);
        int leftCount = rootIndex - ib;
        int rightCount = count - leftCount - 1;
        
        if (leftCount > 0) {
            root->left = buildRecursively(p, pb + 1, pb + leftCount, in, ib, rootIndex - 1, leftCount);
        }
        
        if (rightCount > 0) {
            root->right = buildRecursively(p, pb + leftCount + 1, pe, in, rootIndex + 1, ie, rightCount);
        }
        
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = inorder.size();
        return buildRecursively(preorder, 0, N - 1, inorder, 0, N - 1, N);
    }
};