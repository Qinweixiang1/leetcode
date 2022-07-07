/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* List;
List middleNode(List head){
List Stack[100]={NULL}; int i=0;
List P=head;
while(P){
    Stack[i++]=P;
    P=P->next;
}
i=i/2;
return Stack[i];
}
