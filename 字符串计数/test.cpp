#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    string s1;
    string s2;
    int len1;
    int len2;
    while(cin>>s1>>s2>>len1>>len2){
        int num=0;
        while(s1.size()<len2){
            s1+='a';
        }
        while(s2.size()<len2){
            s2+=(char)('z'+1);
        }
        vector<char> v;
        for(int i=0;i<len2;i++){
            v.push_back(s2[i]-s1[i]);
        }
        for(int i=len1;i<=len2;i++){
            for(int k=0;k<i;k++){
                num=num+v[k]*pow(26,i-k-1);
            }
        }
        cout<<num-1<<endl;
    }
    return 0;
}