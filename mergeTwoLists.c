/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* List;

List mergeTwoLists(List L1, List L2){
List result, tmp;
result=(List)malloc(sizeof(struct ListNode));
tmp=result;
while(L1 && L2){
    if(L1->val < L2->val){
        tmp->next=L1;
        tmp=L1;
        L1=L1->next;
    }
    else{
        tmp->next=L2;
        tmp=L2;
        L2=L2->next;
    }
}
tmp->next= L1==NULL?L2:L1;
return result->next;
}
