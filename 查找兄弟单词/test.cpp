#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool judge(string s1,string s2){
    if(s1.size()>s2.size()||s1.size()<s2.size())
        return false;
    if(s1==s2)
        return false;
    for(auto& e:s1){
        if(s2.find(e)==s2.npos){
            return false;
        }
    }
    unordered_map<char, int> mp;
    for(auto& e:s1){
        mp[e]++;
    }
    for(auto& e:s2){
         mp[e]--;
         if(mp[e]<0){
            return false;
         }
    }
    return true;
}
int main()
{
    int n=0;
    while(cin>>n){
        vector<string> vs;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            vs.push_back(s);
        }
        sort(vs.begin(),vs.end());
        cin>>s;
        cin>>n;
        string s1;
        int num=0;
        for(int i=0;i<vs.size();i++){
            if(judge(s, vs[i])){
                num++;
                if(num==n){
                    s1=vs[i];
                }
            }
        }
        cout<<num<<endl;
        cout<<s1<<endl;
    }
    return 0;
}