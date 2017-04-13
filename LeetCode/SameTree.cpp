/**
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 *
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //Watch out the sequence of the following three lines...
        
        // check if p == NULL and q == NULL, empty meet with empty, happy ending
        if (!p && !q) return true;

        // otherwise, is any of them is empty pointer, then something happened!!
        if (!p || !q) return false;

        // otherwise, they are both not empty pointer, then check its value.
        if (p->val != q->val) return false;
        
        // check its left son and right son, don't worry about their children, if one of them is empty, hehe, some one 
        // would deal with it ;)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
