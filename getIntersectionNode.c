/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode * List;
List getIntersectionNode(List headA, List headB) {
List L1=headA, L2=headB;
while(L1!=L2){
    if(L1)L1=L1->next;
    else L1=headB;

    if(L2)L2=L2->next;
    else L2=headA;

}

return L1;

}
