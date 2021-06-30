#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        vector<int> v;
        for(int i=0;i<n;i++){
            int m=0;
            cin>>m;
            v.push_back(m);
        }
        int num=1;
        vector<int> dp(v.size(),1);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<i;j++){
               if(v[j]<v[i]){
                   dp[i]=max(dp[i],dp[j]+1);
               } 
            }
            num=max(num,dp[i]);
        }
        cout<<num<<endl;
    }
    return 0;
}