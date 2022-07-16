/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* Tree;

void inorder(Tree T,int *n, int k,int *result){
if(T){
    inorder(T->left, n, k,result);
    
    if(*n ==k) {
         *result = T->val; 
        (*n)++;
        return ;
    }else if(*n == k+1) return ;
    (*n)++;

    inorder(T->right, n, k,result);
}
}

int kthSmallest(Tree root, int k){
int n=1;
int result=0;
inorder(root, &n, k,&result);
return result;
}
