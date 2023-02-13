/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
思路一：左右指针
*/
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
int *result= (int*)malloc(sizeof(int)*2);
*returnSize=0;

int left=0, right=numbersSize-1;
while(left<right){
    int sum = numbers[left]+numbers[right];
    if(sum==target){
        *returnSize=2;
        result[0]=left+1;
        result[1]=right+1;
        break;
    }
    if(sum>target)
        right--;
    if(sum<target)
         left++;
}
return result;
}
/*============================================================================*/
/*思路二：先排序，双层循环*/
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int * result = (int*)calloc(2,sizeof(int));
    int i, j;
    for(i=0;i<numsSize;i++)
    {
        int key = target - nums[i];
        for(j = i + 1; j < numsSize; j++)
            if(key == nums[j])
            {
                result[0]=i;
                result[1]=j;
            }
    }
    *returnSize=2;
    return ret;
}
/*============================================================================*/
/*思路二优化：还是双层循环，但是得出答案才分配内存，申请内存地址是非常耗时的，没有答案直接return null*/
/*这个优化和思路一结合应该会更好*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *result=NULL;
    *returnSize=2;
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                 result=(int*)malloc(sizeof(int)*2);
                 result[0]=i;
                 result[1]=j;
                 return result;
            }
        }
    }
    return result;
}
