#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n){
        vector<string> v;
        while(n>=0){
            string s;
           getline(cin,s);
            v.push_back(s);
            n--;
        }
        string s;
        for(int i=1;i<v.size();i++){
            if(v[i].find(',')!=v[i].npos||v[i].find(' ')!=v[i].npos){
                s=s+'"'+v[i]+'"';
            }
            else{
                s+=v[i];
            }
            if(i<v.size()-1){
                s=s+','+' ';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}