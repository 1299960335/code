class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         int num=0;
         for(auto & e:nums){
             num^=e;
         }
         vector<int> v1;
         int num2=1;
         while((num&num2)==0){
             num2<<=1;
         }
         int i=0;int j=0;
         for(auto&e:nums){
             if((e&num2)==0){
                 i=i^e;
             }
             else{
                 j=j^e;
             }
         }
         v1.resize(2);
         v1[0]=i;
         v1[1]=j;
         return v1;
    }
};