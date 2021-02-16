int lengthOfLastWord(char * s){
    if(s==NULL)
       return 0;
   int slen=strlen(s);
   if(slen==0)
       return 0;
   int num=0;
   for(int i=slen-1;i>=0;i--){
        if(s[i]==' '){
            if(num==0) continue;
            break;
        }
        num++;
   }
   return num;
}