char * toLowerCase(char * str){
  if(str==NULL)
  return str;
  int i=strlen(str);
  for(int j=0;j<i;j++){
      if(str[j]>='A'&&str[j]<='Z'){
          str[j]+=32;
      }
  }
  return str;
}