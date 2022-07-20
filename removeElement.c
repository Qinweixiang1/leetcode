int removeElement(int* nums, int numsSize, int val){
int *p1= nums, *p2=nums;
while(p2 < nums+numsSize){
if(*p1==val){
    if(*p2==val){
        p2++;
        continue;
    }
    else{
        *p1=*p2;
        *p2=val;
        p1++;
        p2++;
        continue;
    } 
}
p1++;
p2++;
}
return p1-nums;
}
