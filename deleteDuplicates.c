/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* List;
List deleteDuplicates(List head){
if(!head) 
    return NULL;
List p1=head, p2=head;
while(p2){
    if(p1->val != p2->val){
        p1->next=p2;
        p1=p1->next;
    }
    p2=p2->next;
}
p1->next=NULL;
return head;
}
