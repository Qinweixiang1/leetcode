typedef struct {
int *arr;
int *prearrsum;
int size,total;
} NumArray;



NumArray* numArrayCreate(int* nums, int numsSize) {
NumArray *obj=malloc(sizeof(NumArray));
obj->size=numsSize; obj->total=0;
obj->arr=nums;
obj->prearrsum=(int*)malloc(sizeof(int)*(numsSize+1));
memset(obj->prearrsum,0,sizeof(int)*(numsSize+1));
for(int i=1;i<numsSize+1;i++){
    obj->prearrsum[i] = obj->arr[i-1]+obj->prearrsum[i-1];
}

return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->prearrsum[right+1]-obj->prearrsum[left];
}

void numArrayFree(NumArray* obj) {
free(obj->arr);
free(obj->prearrsum);
free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
