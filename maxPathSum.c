/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode *Tree;

int max(int a, int b){
    return a>b?a:b;
}

int OneSideMax(Tree T,int *result){
    if(T){
        int left = max(OneSideMax(T->left,result),0);
        int right = max(OneSideMax(T->right,result),0);
        *result = max(*result, left+right+T->val);
        return max(left,right)+T->val;
    } 
    return 0;
}

int maxPathSum(Tree T){
    int result = INT_MIN;
    OneSideMax(T,&result);
    return result;
}
