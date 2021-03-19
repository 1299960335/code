class Solution {
public:
    int StrToInt(string str) {
        int n=str.size();
        if(n==0)
           return 0;
        int num=0;
        int i=0;
        if(str[0]=='+'||str[0]=='-'){
            i++;
        }
        for(;i<n;i++){
            if(str[i]>='0'&&str[i]<='9'){
                num*=10;
                num+=(str[i]-'0');
            }
            else{
                return 0;
            }
        }
        if(str[0]=='-'){
            num=(-num);
        }
        return num;
    }
};