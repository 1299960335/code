int* plusOne(int* digits, int digitsSize, int* returnSize){
      if(digits==NULL)
      return NULL;
     *returnSize=digitsSize;
     int size=digitsSize+1;
     int *arr=(int*)malloc(sizeof(int)*size);
     for(int i=0;i<size-1;i++){
        arr[i]=digits[i];
    }
      if(arr[digitsSize-1]!=9){
          arr[digitsSize-1]+=1;
          return arr;
      }
      for(int i=digitsSize-1;i>=0;i--){
          if(arr[i]!=9){
              arr[i]+=1;
              break;
          }
          else if(i!=0&&arr[i]==9){
              arr[i]=0;
          }
          else if(i==0&&arr[i]==9){
              for(int j=0;j<size;j++){
                  arr[j]=0;
              }
              arr[0]=1;
              *returnSize+=1;
              return arr;
          }
      }
      return arr;
}