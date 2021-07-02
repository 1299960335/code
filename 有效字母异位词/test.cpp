class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(s.size()!=t.size())
        return false;
        for(auto& e:s){
            mp[e]++;
        }
        for(auto& e:t){
            mp[e]--;
        }
        for(auto& e:s){
            if(mp[e]!=0)
            return false;
        }
        return true;
    }
};