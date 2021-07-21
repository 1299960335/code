#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n){
        vector<int> v1;
        for(int i=0;i<n;i++){
            int num=0;
            cin>>num;
            v1.push_back(num);
        }
        set<int> si;
        for(auto& e:v1){
            si.insert(e);
        }
        for(auto& e:si){
            cout<<e<<endl;
        }
    }
    return 0;
}