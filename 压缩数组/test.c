int compress(char* chars, int charsSize){
    if(chars==NULL)
    return 0;
    int j=0;
    for(int i=0,k=0;i<charsSize;k=i){
        while(i<charsSize&&chars[i]==chars[k]){
            i++;
        }
        chars[j++]=chars[k];
        if(i-k==1)
        continue;
        char s[1000];
        sprintf(s,"%d",i-k);
        for(int g=0;g<strlen(s);g++){
            chars[j++]=s[g];
        }

    }
    return j;
}