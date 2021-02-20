int* sortArrayByParity(int* A, int ASize, int* returnSize){
      *returnSize=ASize;
      if(A==NULL)
      return NULL;
      int *arr=(int*)malloc(sizeof(int)*ASize);
      int j=0;
      int k=ASize-1;
      for(int i=0;i<ASize;i++){
          if(A[i]%2==0){
              arr[j]=A[i];
              j++;
          }
          else{
             arr[k]=A[i];
             k--;    
          }
      }
      return arr;
}