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
    
    int findRootIndex(const vector<int> &inorder, int begin, int end, int target) {
        for (int i = begin; i <= end; i ++) {
            if (inorder[i] == target) return i;
        }
        
        return -1;
    }
 
    TreeNode *buildTreeRecursively(const vector<int> &inorder, int inbegin, int inend, const vector<int> &postorder, int postbegin, int postend, int count) {
        if (count <= 0) return NULL;
        
        TreeNode *root = new TreeNode(postorder[postend]);
        
        int rootInorder = findRootIndex(inorder, inbegin, inend, postorder[postend]);
        
        int leftCount = rootInorder - inbegin;
        int rightCount = count - leftCount - 1;
        
        if (rightCount > 0) {
            root->right = buildTreeRecursively(inorder, rootInorder + 1, inend, postorder, postend - rightCount, postend - 1, rightCount);
        }
        
        if (leftCount > 0) {
            root->left = buildTreeRecursively(inorder, inbegin, inbegin + leftCount - 1, postorder, postbegin, postbegin + leftCount - 1, leftCount);
        }
        
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = inorder.size();
        
        return buildTreeRecursively(inorder, 0, N - 1, postorder, 0, N - 1, N);
        
    }
};