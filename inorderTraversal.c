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
#define N 10
typedef struct stack *Stack;
typedef struct TreeNode *Tree;

struct stack{
    Tree *base;
    int top;
};

Stack InitStack(Stack S){
    S=(Stack)malloc(sizeof(struct stack));
    S->base=(Tree*)malloc(sizeof(Tree)*N);
    S->top=0;
    return S;
}


int StackFull(Stack S){
    return S->top==N;
}

int StackEmpty(Stack S){
    return S->top==0;
}

int push(Stack S, Tree e){
    if(StackFull(S)) return 0;
    S->base[S->top++]=e;
    return 1;
}

Tree pop(Stack S){
    if(StackEmpty(S)) return NULL;
    return S->base[--(S->top)];
}


int* inorderTraversal(Tree T, int* returnSize){
    int *result=(int*)malloc(sizeof(int)*100); * returnSize=0;
    Stack S;
    S=InitStack(S);
    Tree p=T;
    while(p||!StackEmpty(S)){
        if(p){
            push(S,p);
            p=p->left;
        }
        else{
            p=pop(S);
            result[(* returnSize)++] = p->val;
            p=p->right;
        }
    }
    return result;
}
