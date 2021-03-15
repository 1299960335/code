int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if(nums==NULL)
    return NULL ;
    *returnSize=2;
    int *arr=(int*)malloc(sizeof(int)*2);
    int pre=numsSize-1;
    int cur=0;
    while((nums[pre]+nums[cur])!=target){
        if(nums[pre]+nums[cur]>target){
            pre--;
        }
        else if(nums[pre]+nums[cur]<target){
            cur++;
        }
    }
    arr[0]=nums[cur];
    arr[1]=nums[pre];
    return arr;
}