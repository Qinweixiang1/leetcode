/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define N 10001
typedef struct Node* Tree;

void preorder1(Tree T, int *arr,int *b){
arr[(*b)++]=T->val;
for(int i=0; i< T->numChildren; i++)
    preorder1(T->children[i], arr,b);
}

int* preorder(Tree root, int* returnSize) {
    int b=0;
    *returnSize=0;
    if(!root) return NULL;
    int *result=(int*)malloc(sizeof(int)*N);
    result[b++]=root->val;
    for(int i=0;i<root->numChildren;i++){
        preorder1(root->children[i],result,&b);
    }
    *returnSize=b;
    return result;
}


