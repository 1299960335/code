#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n){
        vector<string> v;
        queue<string> q;
        n+=1;
        while(n){
            string s;
            getline(cin,s);
            if(s!=""){
               size_t i=s.find(' ');
               s=s.substr(i+1);
            }
            v.push_back(s);
            n--;
        }
        int num=0;
        for(int i=0;i<v.size();i++){
            if(!(q.empty())&&q.size()>num){
                num=q.size();
            }
            if(v[i]=="connect"){
                q.push(v[i]);
            }
            else if(!(q.empty())){
                q.pop();
            }
        }
        cout<<num<<endl;
    }
    return 0;
}