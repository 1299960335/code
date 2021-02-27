int Swap(int*_a,int*_b){
    int a=*_a;
    int b=*_b;
    return a-b;
}
int findUnsortedSubarray(int* nums, int numsSize){
      if(nums==NULL||numsSize==1)
      return 0;
      int*nums2=(int*)malloc(sizeof(int)*numsSize);
      memcpy(nums2,nums,sizeof(int)*numsSize);
      qsort(nums2,numsSize,sizeof(int),Swap);
      int begin=0;
      int end=0;
      for(int i=0;i<numsSize;i++){
          if(nums[i]!=nums2[i]){
              begin=i;
              break;
          }
      }
      for(int j=numsSize-1;j>=0;j--){
          if(nums[j]!=nums2[j]){
              end=j;
              break;
          }
      }
      if(end==begin){
          return 0;
      }
      return end-begin+1;
}