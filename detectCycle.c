/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode * List;
List detectCycle(List head) {
    List fast=head,slow=head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) break;
    }
    if(!fast||!fast->next) return NULL;

    slow=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
