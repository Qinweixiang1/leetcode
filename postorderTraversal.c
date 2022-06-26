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
 typedef struct TreeNode* Tree;
void postorder(Tree T, int *Arr,int *i){
if(T){
    postorder(T->left,Arr,i);
    postorder(T->right,Arr,i);
    Arr[(*i)++]=T->val;
}
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){
int * result = (int *)malloc(sizeof(int)*100); *returnSize=0;
postorder(root,result,returnSize);
return result;
}



/*非递归*/
typedef struct TreeNode* Node;
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    Node stack[100]={[99]=NULL};     int stacknum=0;
    Node r=NULL;
    int * result=(int *)malloc(sizeof(int)*100);    *returnSize=0;
    Node p = root;
    while(p|| stacknum!=0)
    {
        if(p){
            //左右根
            stack[stacknum++]=p;
            p=p->left;
        }
        else{
            p=stack[stacknum-1];
            if(p->right && p->right != r)
                p=p->right;
            else {
                p=stack[--stacknum];
                result[(*returnSize)++]=p->val;
                r=p;
                p=NULL;
            }
        }
    }
    return result;
}
