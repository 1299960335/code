#include<iostream>
#include<string>
using namespace std;
string add(string& s)
{
    int size=s.size();
    int count=0;
    for(int i=0;i<s.size();i++){
        count=count+s[i]-'0';
    }
    string s1=to_string(count);
    return s1;
}
int main()
{
    string s;
    while(cin>>s){
        while(s.size()>1){
            s=add(s);
        }
        cout<<s<<endl;
    }
    return 0;
}