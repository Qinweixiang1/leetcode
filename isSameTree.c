/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode* Tree;
bool isSameTree(Tree p, Tree q){
if(p&&q){ //p q都有
    if(!isSameTree(p->left,q->left)) return 0;
    if(!isSameTree(p->right,q->right)) return 0;
}
if(p||q){ //p有或者q有
    if(p){  
        if(q){
            return p->val==q->val;  //p q都有
        }
        return 0; //p有 q没有
    }
    return 0;  //p没有  q有
}
return 1;  //p q都没有
}
