#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n){
        vector<string> v;
        vector<bool> v1(n+1,true);
        n+=1;
        while(n--){
            string s;
            getline(cin,s);
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==v[i+1]){
                v1[i]=false;
            }
            else if(v[i].size()<v[i+1].size()&&v[i]==v[i+1].substr(0,v[i].size())&&v[i+1][v[i].size()]=='/'){
                v1[i]=false;
            }
        }
        string s1="mkdir -p ";
        for(int i=1;i<v.size();i++){
            if(v1[i]){
               v[i]=s1+v[i];
               cout<<v[i]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}