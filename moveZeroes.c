void moveZeroes(int* nums, int numsSize){
int *p1=nums, *p2=nums;
while(p2<nums+numsSize){
    if(*p1==0){
        if(*p2==0){
            p2++;
            continue;
        }
        else{
            *p1=*p2;
            *p2=0;
            p1++;
            p2++;
            continue;
        }
    }
    p1++;
    p2++;
}
}
