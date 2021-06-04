#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string nums(int num)
{
    if(num==1){
        return "0001";
     }
    if(num==2){
        return "0002";
    }
    int num1=1;
    int num2=2;
    int num3=0;
    num-=2;
    while(num--){
        num3=num2;
        num2=(num2+num1)%10000;
        num1=num3;
        num3=num2;
    }
    string s=to_string(num3);
    if(s.size()<4){
        reverse(s.begin(),s.end());
        int size=4-s.size();
        while(size--){
            s+='0';
        }
        reverse(s.begin(),s.end());
    }
    return s;
}
int main()
{
    int num=0;
    while(cin>>num){
        vector<int> v;
        while(num--){
            int n=0;
            cin>>n;
            v.push_back(n);
        }
        string s("");
        for(int i=0;i<v.size();i++){
            s+=nums(v[i]);
        }
        cout<<s<<endl;
    }
    return 0; 
}