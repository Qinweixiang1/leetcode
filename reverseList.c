/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* List;
struct ListNode* reverseList(struct ListNode* head){
List current=head;
List prev=NULL;
while(current)
{
List next=current->next;
current->next=prev;
prev=current;
current=next;
}
return prev;
}


/*  法2  */
typedef struct ListNode* List;

List reverseList(List head){
    List stack[5000]={NULL}; int i=0;
    List p=head;
    if(!p)return NULL;
    while(p){
        stack[i++]=p;
        p=p->next;
    }
    p=stack[--i];
    List tmp=p;
    while(i){
        p->next=stack[--i];
        p=p->next;
    }
    p->next=NULL;
    return tmp;
}
