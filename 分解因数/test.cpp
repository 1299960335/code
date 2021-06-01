#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool judge(int n)
{
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main()
{
    int n=0;
    while(cin>>n){
        int a=n;
        vector<int> v;
        for(int i=2;i<=sqrt(n);i++){
            while(n%i==0&&n!=1){
                v.push_back(i);
                n/=i;
            }
        }
        if(n>1&&judge(n)){
            v.push_back(n);
        }
        cout<<a<<" = "<<v[0];
        for(int i=1;i<v.size();i++){
            cout<<" * "<<v[i];
        }
        cout<<endl;
    }
    return 0;
}