#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n)
    {
        vector<string> v1;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            v1.push_back(s);
        }
        vector<string> v2;
        for(int i=0;i<v1.size();i++){
            s="";
            for(int j=0;j<v1[i].size();j++){
                if(v1[i][j]!='-'){
                    s+=v1[i][j];
                }
            }
            s.insert(3,"-");
            v2.push_back(s);
        }
        for(int i=0;i<v2.size();i++){
            for(int j=0;j<v2[i].size();j++){
                if(v2[i][j]>='A'&&v2[i][j]<='Z'){
                    if(v2[i][j]=='A'||v2[i][j]=='B'||v2[i][j]=='C'){
                        v2[i][j]='2';
                    }
                    else if(v2[i][j]=='D'||v2[i][j]=='E'||v2[i][j]=='F'){
                        v2[i][j]='3';
                    }
                    else if(v2[i][j]=='G'||v2[i][j]=='H'||v2[i][j]=='I'){
                         v2[i][j]='4';
                    }
                    else if(v2[i][j]=='J'||v2[i][j]=='K'||v2[i][j]=='L'){
                        v2[i][j]='5';
                    }
                    else if(v2[i][j]=='M'||v2[i][j]=='N'||v2[i][j]=='O'){
                        v2[i][j]='6';
                    }
                    else if(v2[i][j]=='P'||v2[i][j]=='Q'||v2[i][j]=='R'||v2[i][j]=='S'){
                        v2[i][j]='7';
                    }
                    else if(v2[i][j]=='T'||v2[i][j]=='U'||v2[i][j]=='V'){
                        v2[i][j]='8';
                    }
                    else if(v2[i][j]=='W'||v2[i][j]=='X'||v2[i][j]=='Y'||v2[i][j]=='Z'){
                        v2[i][j]='9';
                    }
                }
            }
        }
        sort(v2.begin(),v2.end());
        for(int i=0;i<v2.size()-1;i++){
            if(v2[i]!=v2[i+1]){
                cout<<v2[i]<<endl;
            }
        }
        cout<<v2[v2.size()-1]<<endl;
        cout<<endl;
    }
    return 0;
}