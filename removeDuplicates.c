int removeDuplicates(int* nums, int numsSize){
if(!numsSize) 
    return 0;

int fast=0, slow=0;
int count=1;

while(fast<numsSize){
    if(nums[fast]==nums[slow])
        fast++;
    else{
        nums[++slow]=nums[fast];
        count++;
    }
}
return count;
}
