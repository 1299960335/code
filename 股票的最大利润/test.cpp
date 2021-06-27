class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        return 0;
        int min=prices[0];
        int num=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            if(num<prices[i]-min){
                num=prices[i]-min;
            }
        }
        return num;
    }
};