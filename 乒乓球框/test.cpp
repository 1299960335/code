#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
string judge(string s1,string s2){
     if(s2.size()>s1.size()){
         return "No";
        }
        else{
            unordered_map<char, int> mp;
            int i=0;
            while(i<s2.size()){
                if(s1.find(s2[i])==s2.npos){
                    return "No";
                }
                i++;
            }
            for(auto& e:s1){
                mp[e]++;
            }
            for(auto& e:s2){
                mp[e]--;
                if(mp[e]<0){
                   return "No";
                }
            }
            return "Yes";
        }
}
int main()
{
    string s1;
    while(cin>>s1){
        string s2;
        cin>>s2;
        string s=judge(s1, s2);
        cout<<s<<endl;
    }
    return 0;
}