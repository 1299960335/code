#include<iostream>
using namespace std;
int main()
{
    int n=0;
    long long num[21]={0,0,1};
    for(int i=3;i<21;i++){
        num[i]=(i-1)*(num[i-1]+num[i-2]);
    }
    while(cin>>n){
        cout<<num[n]<<endl;
    }
    return 0;
}