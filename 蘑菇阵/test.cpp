#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n=0,m=0,k=0;
    while(cin>>n>>m>>k){
        vector<vector<int>> vv(m+1,vector<int>(n+1));
        vector<vector<double>> vd(m+1,vector<double>(n+1));
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            vv[x][y]=1;
        }
        vd[1][1]=1.0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(!(i==1&&j==1)){
                    vd[i][j]=vd[i][j-1]*(i==m?1:0.5)+vd[i-1][j]*(j==n?1:0.5);
                    if(vv[i][j]==1)
                        vd[i][j]=0;
                }
            }
        }
        printf("%.2lf\n",vd[m][n]);
    }
}