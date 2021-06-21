#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int num=0;
    int num2=0;
    cin>>num2;
    while(num2--){
        cin>>num;
        num*=2;
        vector<int> v1(num);
        int n=0;
        cin>>n;
        for(int i=0;i<num;i++){
            cin>>v1[i];
        }
        vector<int> v2;
        while(n--){
            int size=v1.size()/2;
            int i=size-1;
            int j=v1.size()-1;
            while(size--){
                v2.push_back(v1[j]);
                v2.push_back(v1[i]);
                j--;
                i--;
            }
            reverse(v2.begin(),v2.end());
            v1=v2;
            v2.clear();
        }
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}