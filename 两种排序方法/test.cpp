#include<iostream>
#include<string>
#include<vector>
using namespace std;
string slenth(vector<string>& v)
{
    string s;
    for(int i=0;i<v.size()-1;i++){
        if(v[i].size()>v[i+1].size()){
            s="none";
            return s;
        }
    }
    s="lengths";
    return s;
}
string slex(vector<string>& v)
{
    string s;
    int i=0;
    while(i<v.size()-1){
         if(v[i].compare(v[i+1])>0){
            s="none";
            return s;
         }
        i++;
    }
    s="lexicographically";
    return s;
}
int main()
{
    vector<string> v;
    int n=0;
    cin>>n;
    while(n>=0){
        string s;
        getline(cin,s);
        v.push_back(s);
        n--;
    }
    string s1=slex(v);
    string s2=slenth(v);
    if(s1=="lexicographically"&&s2=="lengths")
        cout<<"both"<<endl;
    else if(s1=="lexicographically"&&s2!="lengths")
        cout<<"lexicographically"<<endl;
    else if(s1!="lexicographically"&&s2=="lengths")
        cout<<"lengths"<<endl;
    else
        cout<<"none"<<endl;
    return 0;
}