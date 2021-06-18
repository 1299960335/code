#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s1;
    string s2;
    while(cin>>s1>>s2){
        vector<vector<int>> vv(s1.size()+1,vector<int>(s2.size()+1));
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    vv[i][j]=vv[i-1][j-1]+1;
                }
                else{
                    vv[i][j]=vv[i-1][j]>vv[i][j-1]?vv[i-1][j]:vv[i][j-1];
                }
            }
        }
        cout<<vv[s1.size()][s2.size()]<<endl;
    }
    return 0;
}