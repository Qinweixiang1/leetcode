/**
 * Note: The returned array must be malloced, assume caller calls free().
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
