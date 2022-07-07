/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode * List;
bool hasCycle(List head) {
    List p1=head,p2=head;
    while(p1&&p2){
        p1=p1->next;
        if(p2->next) p2=p2->next->next;
        else return 0;

        if(p1==p2) return 1;
    }
    return 0;
}
