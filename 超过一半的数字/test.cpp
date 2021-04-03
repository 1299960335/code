class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
       sort(numbers.begin(),numbers.end());
       int i=numbers.size()/2;
        int j=0;
       for(auto &e:numbers){
           if(numbers[i]==e){
               j++;
           }
       }
        if(j>i){
            return numbers[i];
        }
        return 0;
    }
};