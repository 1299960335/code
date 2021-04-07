class Solution {
public:
    vector<string> letterCombinations(string digits) {
     if(digits.size()==0)
     return {};
     vector<string> phone={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     int i=0;
     vector<string> ret;
     ret.push_back("");
     while(i<digits.size()){
         vector<string> tmp;
         for(string s:ret){
             for(char data:phone[digits[i]-'0']){
                 tmp.push_back(s+data);
             }
         }
        ret.swap(tmp);
        i++;
     }
     return ret;
    }
};