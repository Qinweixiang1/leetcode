/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize){
int *result=(int*)malloc(sizeof(int)*numsSize);
int i=0;
for(;i<numsSize;i++){
    result[i]=nums[nums[i]];
}
*returnSize=i;
return result;
}
