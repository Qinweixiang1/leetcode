/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*递归*/
#define N 100
typedef struct TreeNode* Tree;

void preorder(Tree T,int *a,int *n){
if(T){
  a[(*n)++]=T->val;
  preorder(T->left,a,n);
  preorder(T->right,a,n);
}
}

int* preorderTraversal(Tree T, int* returnSize){
  int *result=(int*)malloc(sizeof(int)*N); *returnSize = 0;
  preorder(T,result,returnSize);
  return result;
}

/*非递归*/
