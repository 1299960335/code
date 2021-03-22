class Solution {
public:
    string addStrings(string num1, string num2) {
     string str;
     int size1=num1.size()-1;
     int size2=num2.size()-1;
     char tmp=0;
     while(size1>=0||size2>=0){
        char x1=0,x2=0;
        if(size1>=0){
           x1=num1[size1]-'0';
           size1--;
        }
        if(size2>=0){
            x2=num2[size2]-'0';
            size2--;
        }
        char strs=x1+x2+tmp;
        if(strs>=10){
            strs-=10;
            tmp=1;
        }
        else{
            tmp=0;
        }
        str+=(strs+'0');
     }
    if(tmp==1){
        str+='1';
     }
    reverse(str.begin(),str.end());
    return str;
    }
};