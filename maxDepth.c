/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
typedef struct Node* Tree;
#define max(a,b) ((a)>(b)?(a):(b))


void traverse(Tree T,int *res, int *depth){
    if(!T) 
        return ;

    if(!T->numChildren){
        *res=max((*depth)+1, *res) ;
        return ;
    }

    for(int i=0; i < T->numChildren; i++){
            (*depth)++;
            traverse(T->children[i],res, depth);
            (*depth)--;
    }
}


int maxDepth(Tree root) {
    int res =0, depth=0;
   traverse(root, &res, &depth);
   return res;
}
