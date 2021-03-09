int missingNumber(int* nums, int numsSize){
   if(nums==NULL)
   return 0;
   int i=0;
   for(int j=0;j<numsSize;j++){
       if(nums[j]==i){
           i++;
       }
       else{
           break;
       }
   }
   return i;
}