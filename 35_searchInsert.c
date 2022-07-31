int searchInsert(int* nums, int numsSize, int target){
    int left=0, right = numsSize - 1;
    int mid = numsSize / 2;
    while(left<=right){
        if( nums[mid] > target)
            right = mid - 1;    

        if(nums[mid] < target)
            left = mid + 1;

        if(nums[mid] == target) 
            return mid;

        mid= ((right-left) / 2) + left;
    }
    return left ;
}
