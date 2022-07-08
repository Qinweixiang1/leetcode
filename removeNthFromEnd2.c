/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* List;
List removeNthFromEnd(List head, int n){
List p=head,q=head,pre;
while(n){
    n--;
    p=p->next;
}

if(!p) return head->next;

while(p){
    p=p->next;
    pre=q;
    q=q->next;
}

pre->next=pre->next->next;
return head;

}






