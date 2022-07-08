/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
struct ListNode *stack[30];
int i=0;
struct ListNode* p = head;
while(p)
{
stack[i++]=p;
p=p->next;
}
if(i<2) return NULL;
if(i==n) {head=head->next; return head;}
stack[i-n-1]->next=stack[i-n]->next;
return head;
}
