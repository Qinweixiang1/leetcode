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

/*递归*/
typedef struct TreeNode* Tree;
int maxDepth(Tree T){
    return T == NULL ? 0 : fmax(maxDepth(T->left), maxDepth(T->right)) + 1; 
}




/*先序*/
typedef struct TreeNode* Tree;
#define max(a,b) ((a)>(b)?(a):(b))

void traverse(Tree T, int *depth, int *result){
if(T){
    (*depth)++;
    if(!T->left && !T->right) *result = max(*result, *depth);
    traverse(T->left, depth, result);
    traverse(T->right, depth, result);
    (*depth)--;
}
}


int maxDepth(Tree root){
int depth=0;
int result=0 ;
traverse(root, &depth, &result);
return result;
}
