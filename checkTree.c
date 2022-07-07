/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* Tree;

bool checkTree(Tree root){
return root->left->val + root->right->val == root->val;
}
