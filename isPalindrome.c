/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode*  List ;

bool isPalindrome(List head){
int arr[100000]={0}; int i=0,j=0,k=0;
List p=head;
while(p){
    arr[k++]=p->val;
    p=p->next;
}
j=k;
while(i < k/2){
if(arr[i++]==arr[--j]) continue;
return 0;
}
return 1;

}
