/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode * Tree, *Node;

Tree lowestCommonAncestor(Tree root,  Node p, Node q) {
    while(1){
    if(root->val > p->val && root->val > q->val)
        root=root->left;
    else if(root->val < p->val && root->val < q->val)
        root=root->right;
    else 
        return root;
    }
}
