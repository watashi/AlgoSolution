/**
 Given a binary tree

     struct TreeLinkNode {
       TreeLinkNode *left;
       TreeLinkNode *right;
       TreeLinkNode *next;
     }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

 Initially, all next pointers are set to NULL.

 Note:

 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,

          1
        /  \
       2    3
      / \  / \
     4  5  6  7
 After calling your function, the tree should look like:

          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \  / \
     4->5->6->7 -> NULL
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeLinkNode *curr = root;
        
        // Remember to check if (root == NULL)
        while (curr && curr->left) {
            curr->left->next = curr->right;
            
            TreeLinkNode *tmpCurr = curr->next;
            TreeLinkNode *tmpTail = curr->right;
            while (tmpCurr) {
                tmpTail->next = tmpCurr->left;
                tmpCurr->left->next = tmpCurr->right;
                
                tmpTail = tmpCurr->right;
                tmpCurr = tmpCurr->next;
            }
            
            curr = curr->left;
        }
    }
};