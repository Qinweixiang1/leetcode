/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
int *result=(int*)malloc(sizeof(int)*n);
memset(result,0,sizeof(int)*n);

int *diff=(int*)malloc(sizeof(int)*n);
memset(diff,0,sizeof(int)*n);


for(int i=0; i<bookingsSize; ++i){
    diff[bookings[i][0]-1]+=bookings[i][2] ;
    if(bookings[i][1]<n)
        diff[bookings[i][1]]-=bookings[i][2];
}
result[0]=diff[0];
for(int i=1; i<n;++i){
    result[i]=result[i-1]+diff[i];
}
*returnSize=n;
 return result;
}
