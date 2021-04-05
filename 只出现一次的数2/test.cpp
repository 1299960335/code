class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seeonce =0;
        int seetwice=0;
        for(auto &e:nums){
            seeonce=~seetwice&(seeonce^e);
            seetwice=~seeonce&(seetwice^e);
        }
        return seeonce;
    }
};