/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define N 256
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



int maxDepth(Tree T){
    if(!T) return 0;
    int last=1, level=0;
    Tree queue[N];
    Queue Q;
    Q=InitQueue(Q);
    EnQueue(Q, T);
    Tree P;
    while(!QueueEmpty(Q)){
        DeQueue(Q,&P);
        if(P->left) EnQueue(Q,P->left);
        if(P->right) EnQueue(Q,P->right); 
        if(Q->front == last) {
            level++;
            last=Q->rear;  
        }

    }
    return level;
}
