void rotate(int* nums, int numsSize, int k){
    if(nums==NULL){
        return ;
    }
    int b=k%numsSize;
    if(b==0){
        return;
    }
    for(int i=0;i<numsSize/2;i++){
        int temp=0;
        temp=nums[i];
        nums[i]=nums[numsSize-1-i];
        nums[numsSize-1-i]=temp;
    }
    for(int j=0;j<b/2;j++){
        int temp=0;
        temp=nums[j];
        nums[j]=nums[b-j-1];
        nums[b-j-1]=temp;
    }
    for(int k=0;k<(numsSize-b)/2;k++){
        int temp=0;
        temp=nums[k+b];
        nums[k+b]=nums[numsSize-1-k];
        nums[numsSize-1-k]=temp;
    }
}