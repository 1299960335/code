class Solution {
public:
    string reverseWords(string s) {
        int len=s.size();
        int i=0;
        int j=0;
        string s2=s;
        while(i<len&&j<len)
        {
            j=s2.find(' ',j+1);
            if(j==-1){
                j=len;
            }
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
        }
        return s;
    }
};