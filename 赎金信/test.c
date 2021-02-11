bool canConstruct(char * ransomNote, char * magazine){
    if(ransomNote==NULL||magazine==NULL)//如果传入值为空，则直接返回
    return false;
    int a=strlen(ransomNote);//计算a字符串长度
    int b=strlen(magazine);//计算b字符串长度
    if(a>b)//如果a大于b直接返回（没得比）
    return false;
    int ran[26]={0};//创建两个记录26个字母出现次数的数组
    int mag[26]={0};
    for(int i=0;i<a;i++){//出现某个字母，则次数加1
        ran[ransomNote[i]-'a']+=1;
    }
    for(int j=0;j<b;j++){
        mag[magazine[j]-'a']+=1;
    }
    for(int k=0;k<26;k++){//比较两个数组中的值是否相等，不相等返回false
        if(ran[k]>mag[k]){
            return false;
        }
    }
    return true;
}