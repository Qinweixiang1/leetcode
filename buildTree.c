/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* Tree ;

Tree buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
if(!preorderSize||!inorderSize) return NULL;
Tree T=(Tree)malloc(sizeof(struct TreeNode));
T->val=preorder[0];
int i=0;
while(T->val != inorder[i]) i++;
T->left=buildTree(preorder+1,i,inorder,i);    
T->right=buildTree(preorder+1+i,preorderSize-1-i,inorder+i+1,inorderSize-i-1);
return T;
}
