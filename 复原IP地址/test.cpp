class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    bool judge(string& s)
    {
        if(s.size() != 1 && s[0] == '0' || stoi(s) > 255){
            return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        for(int i = 1;i <= 3;i++){
            for(int j = 1;j <= 3;j++){
                for(int k = 1;k <= 3;k++){
                    for(int m = 1;m <= 3;m++){
                        if((i+k+j+m) == s.size()){
                            string s1 = s.substr(0,i);
                            string s2 = s.substr(i,j);
                            string s3 = s.substr(i+j,k);
                            string s4 = s.substr(i+j+k,m);
                            if(judge(s1) && judge(s2) && judge(s3) && judge(s4)){
                                string tt = s1 + "." + s2 + "." + s3 + "." + s4;
                                v.push_back(tt);
                            }
                        }
                    }
                }
            }
        }
        return v;
    }
};