#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> vv(10,vector<int>(10));
void DFS(vector<string>& v,int i,int j,int ret,int& num)
{
    if(i<0||j<0||i>=10||j>=10||v[i][j]=='#'||ret>num||vv[i][j]){
        return ;
    }
    if(i==9&&j==8){
        if(ret<num){
            num=ret;
            return ;
        }
    }
    vv[i][j]=1;
    DFS(v,i+1,j,ret+1,num);
    DFS(v,i,j+1,ret+1,num);
    DFS(v,i-1,j,ret+1,num);
    DFS(v,i,j-1,ret+1,num);
    vv[i][j]=0;
}
int main()
{
    vector<string> v(10);
    while(cin>>v[0]){
        int num=__INT_MAX__;
        for(int i=1;i<10;i++){
            cin>>v[i];
        }
        DFS(v,0,1,0,num);
        cout<<num<<endl;
    }
    return 0;
}