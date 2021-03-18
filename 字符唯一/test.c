int  Swap(const void*a,const void*b ){
    return *(char*)a-*(char*)b;
}
bool isUnique(char* astr){
   if(astr==NULL)
   return false;
   int num=strlen(astr);
   qsort(astr,num,sizeof(char),Swap);
   for(int i=0;i<num-1;i++){
       if(astr[i]==astr[i+1]){
           return false;
       }
   }
   return true;
}