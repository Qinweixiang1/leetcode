/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* List;
List partition(List head, int x){
List l1=(List)malloc(sizeof(struct ListNode));
List l2=(List)malloc(sizeof(struct ListNode));
//l1放小的，l2放大的
List tmp1=l1,tmp2=l2;

while(head){
    if(head->val < x){
        tmp1->next=head;
        tmp1=tmp1->next;
    }
    else{
        tmp2->next=head;
        tmp2=tmp2->next;
    }
    head=head->next;
}
tmp2->next=NULL;
tmp1->next=l2->next;
return l1->next;
}
