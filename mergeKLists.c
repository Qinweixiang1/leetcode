/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define N 10010
typedef struct ListNode* List;


void max_heapify(List *arr, int i, int n){
    List tmp = arr[i];
    int j=i*2;
    while(j<=n){
        if(j<n && arr[j]->val < arr[j+1]->val)
            j++;
        if(arr[j]->val < tmp->val)
            break;
        arr[j/2]=arr[j];
        j=j*2;
    }
    arr[j/2]=tmp;
}



void build_heap(List *arr, int n){
    for(int i=n/2; i>=1; i--)
        max_heapify(arr,i, n-1);
}

void heapSort(List *arr,int n){
    int i;
    List tmp;
    for(i=n-1; i>=2; i--){
        tmp=arr[i];
        arr[i]=arr[1];
        arr[1]=tmp;
        max_heapify(arr, 1, i-1);
    }
}


List mergeKLists(List* lists, int listsSize){
List *heap=(List*)malloc(sizeof(List)*N); int n=1;

for(int i=0; i<listsSize; i++){
    List L=lists[i];
    while(L){
        heap[n++]=L;
        L=L->next;
    }
}
build_heap(heap,n);
heapSort(heap,n);
List res=(List)malloc(sizeof(struct ListNode));
List p=res;
for(int i=1; i<n; i++){
    p->next=heap[i];
    p=p->next;
}
p->next=NULL;
return res->next;
}
