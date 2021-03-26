bool respade(char s)
{
    if(s>='a'&&s<='z'||
       s>='A'&&s<='Z'||
       s>='0'&&s<='9')
       {
           return true;
       }
       return false;
}
class Solution {
public:
    bool isPalindrome(string s) {
          for(int i=0;i<s.size();i++){
              if(s[i]>='A'&&s[i]<='Z'){
                  s[i]+=32;
              }
          }
          int begin=0;
          int end=s.size()-1;
          while(begin<end){
              if(begin<end&&!(respade(s[begin]))){
                 begin++;
                 continue;
              }
              if(begin<end&&!(respade(s[end]))){
                 end--;
                 continue;
              }
              if(begin<end&&s[begin]!=s[end]){
                  return false;
              }
              else{
                   begin++;
                   end--;
              }
          }
          return true;     
    }
};