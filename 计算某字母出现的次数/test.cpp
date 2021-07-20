#include<iostream>
#include<unordered_map>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    char c;
    cin>>c;
    c=tolower(c);
    unordered_map<char, int> mp;
    for(auto& e:s){
            e=tolower(e);
    }
    for(auto& e:s){
            mp[e]++;
    }
    cout<<mp[c]<<endl;
    
    return 0;
}