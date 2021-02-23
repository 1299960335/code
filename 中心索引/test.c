int pivotIndex(int* nums, int numsSize){
    if(nums==NULL)
    return -1;
    int add=0;
    for(int i=0;i<numsSize;i++){
        add+=nums[i];
    }
    int sum=0;
    for(int i=0;i<numsSize;i++){
        if(2*sum+nums[i]==add){
            return i;
        }
        sum+=nums[i];
    }
    return -1;
}