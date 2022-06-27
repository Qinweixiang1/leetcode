/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define N 1024
typedef struct TreeNode* Tree;
typedef struct queue {
    Tree *base;
    int rear, front;
} *Queue;

Queue InitQueue(Queue Q){
    Q=(Queue)malloc(sizeof(struct queue));
    if(!Q) return NULL;
    Q->base=(Tree *)malloc(sizeof(Tree)*N);
    if(!Q->base) return NULL;
    Q->rear=0; Q->front=0;
    return Q;
}

int QueueFull(Queue Q){
    return (Q->rear+1)%N==Q->front;
}

int QueueEmpty(Queue Q){
    return Q->rear==Q->front;
}
int QueueLength(Queue Q){
    return (Q->rear - Q->front + N) % N;
}

int EnQueue(Queue Q,Tree e){
    if(QueueFull(Q)) return 0;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%N;
    return 1;
}

int DeQueue(Queue Q, Tree *e){
    if(QueueEmpty(Q)) return 0;
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%N;
    return 1;
}

int** levelOrder(Tree T, int* returnSize, int** returnColumnSizes){
    int **result=(int**)malloc(sizeof(int*)*760);
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int)*760);
    if(!T) return NULL;
    int last=1, level=0;
    Tree queue[N];
    Queue Q;
    Q=InitQueue(Q);
    EnQueue(Q, T);
    Tree P;
    int i=0;
    int a[N]={0};
    while(!QueueEmpty(Q)){
        DeQueue(Q,&P);
        a[i++]=P->val;
        if(P->left) EnQueue(Q,P->left);
        if(P->right) EnQueue(Q,P->right); 
        if(Q->front == last) {
            int *tmp=(int*)malloc(sizeof(tmp)*i);
            for(int b=0;b<i;b++)
                tmp[b]=a[b];
            result[level]=tmp;
            (*returnColumnSizes)[level++]=i; 
            *returnSize=level;
            last=Q->rear;  
            i=0;
        }
    }
    return result;
}
