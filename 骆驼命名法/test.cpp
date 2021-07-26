#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string s;
    while(cin>>s){
        string s1;
        for(int i=0;i<s.size();i++){
            size_t j=s.find('_',i);
            string s2=s.substr(i,j-i);
            s2[0]=toupper(s2[0]);
            s1+=s2;
            if(j!=s.npos){
                i=j;
            }
            else{
                break;
            }
        }
        s1[0]=tolower(s1[0]);
        cout<<s1<<endl;
    }
    return 0;
}