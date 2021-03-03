int* sortedSquares(int* nums, int numsSize, int* returnSize){
      int *arr=(int*)malloc(sizeof(int)*numsSize);
      int j=numsSize-1;int i=0;
      int k=j;
    while(i<=j){
         int tmp=nums[i]*nums[i];
         int pem=nums[j]*nums[j];
         if(tmp>pem){
             arr[k--]=tmp;
             i++;
         }
         else{
             arr[k--]=pem;
             j--;
         }
    }
    * returnSize=numsSize;
    return arr;
}