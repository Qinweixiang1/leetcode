/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define N 1024
typedef struct TreeNode * Tree;
void preorder(Tree T, Tree *Q, int *n){
    if(T){
        Q[(*n)++]=T;
        preorder(T->left,Q,n);
        preorder(T->right,Q,n);
    }
}

void preorderlink(Tree *Q,int n){
    Tree p;
    for(int i=0;i<n-1;i++){
        p=Q[i];
        p->left=NULL;
        p->right=Q[i+1];
    }
}

void flatten(Tree T){
    Tree queue[N]={NULL}; int n=0;
    preorder(T,queue,&n);
    preorderlink(queue,n);
}
