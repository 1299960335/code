#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    while(cin>>s1){
         string s2;
         string s3;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A'&&s1[i]<='Z'){
            s2+=s1[i];
        }
        else{
            s3+=s1[i];
        }
    }
    s3+=s2;
    cout<<s3<<endl;
        s1="";
    }
}