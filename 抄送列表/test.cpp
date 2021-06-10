#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s)){
       string s1;
        getline(cin,s1);
        vector<string> v;
        size_t i=0;
        string s2;
        while(i<s.size()){
          if(s[i]!='"'&&s[i]!=','){
              s2+=s[i];
              i++;
          }
          else if(s[i]=='"'){
              size_t j=s.find('"',i+1);
              s2=s.substr(i+1,j-i-1);
              v.push_back(s2);
              i=j+1;
          }
          else{
               v.push_back(s2);
               s2="";
               i++;
            }
        }
        v.push_back(s2);
        string s3="";
        for(int i=0;i<v.size();i++){
            if(v[i]==s1){
                s3="Ignore";
                cout<<s3<<endl;
                break;
            }
        }
        if(s3!="Ignore"){
            cout<<"Important!"<<endl;
        }
     }
    return 0;
}