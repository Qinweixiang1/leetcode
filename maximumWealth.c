#define MAX(a,b) (a>b)?a:b

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
int i=0,j=0,sum=0,max=0;
while(i<accountsSize){
    while(j<*accountsColSize){
        sum+=accounts[i][j++];
    }
    i++;
    max = MAX(max,sum);
    sum=0;
    j=0;
}
return max;
}
