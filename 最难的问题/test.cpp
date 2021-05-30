#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s)){
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                if(s[i]>'E'){
                    s[i]=s[i]-5;
                }
                else{
                    s[i]=s[i]+21;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}