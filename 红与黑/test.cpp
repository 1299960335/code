#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<vector<char>>& vv,int x,int y,int& cont)
{
    if(x<0||x>=vv.size()||y<0||y>=vv[0].size()||vv[x][y]=='#')
        return ;
    cont++;
    vv[x][y]='#';
    DFS(vv,x+1,y,cont);
    DFS(vv,x,y+1,cont);
    DFS(vv,x-1,y,cont);
    DFS(vv,x,y-1,cont);
}
int main()
{
    int n=0,m=0;
    int cont=0;
    while(cin>>n>>m){
        vector<vector<char>> vv(n,vector<char>(m));
        int x=0,y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>vv[i][j];
                if(vv[i][j]=='@'){
                    x=i;
                    y=j;
                }
            }
        }
        DFS(vv,x,y,cont);
        cout<<cont<<endl;
        cont=0;
    }
    return 0;
}