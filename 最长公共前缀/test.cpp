class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if(strs.empty())
        return s;
        sort(strs.begin(),strs.end());
        s=strs[0];
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                if(s.size()>0&&s[j]!=strs[i][j]){
                    s.resize(j);
                    break;
                }
                else if(s.size()==0){
                    return s;
                }
            }
        }
        return s;
    }
};