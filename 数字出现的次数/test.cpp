int search(int* nums, int numsSize, int target){
    if(nums==NULL)
    return 0;
    int i=0;
    for(int j=0;j<numsSize;j++){
        if(nums[j]==target){
            i++;
        }
    }
    return i;
}