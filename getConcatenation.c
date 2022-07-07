/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
int *ans=(int*)malloc(sizeof(int)*numsSize*2);
int i=0,k=0;
while(i++<2)
    for(int j=0;j<numsSize;j++)
        ans[k++]=nums[j];
*returnSize=numsSize*2;
return ans;
}
