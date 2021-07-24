#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s)){
        vector<string> vs;
        string s1;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                s1+=s[i];
            }
            else{
                if(s1!=""){
                  vs.push_back(s1);
                }
                s1.clear();
            }
        }
        vs.push_back(s1);
        s1.clear();
        reverse(vs.begin(),vs.end());
        for(int i=0;i<vs.size();i++){
            s1+=vs[i]+' ';
        }
        s1.pop_back();
        cout<<s1<<endl;
    }
    return 0;
}