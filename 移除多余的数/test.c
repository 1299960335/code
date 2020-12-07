int removeDuplicates(int* nums,int numsSize){
       if(nums==NULL||numsSize==0){
                    return 0;
           }
     else if(numsSize==1){
               return 1;
            }
         int size=0;
        for(int i=0;i<numsSize-1;i++){
        if(nums[i]!=nums[i+1]){
             nums[size]=nums[i];
                 size++;
             }
          }
         nums[size]=nums[numsSize-1];
          size++;
        return size;
}
