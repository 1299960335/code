#include<iostream>
#include<vector>
using namespace std;
void DFS(int n,int m,vector<int> v,int begin)
{
    if (m == 0) {
        for (int i = 0; i<v.size(); i++) {
            i == 0 ? cout << v[i] : cout << " " << v[i];
        }
        cout << endl;
    }
    for (int i = begin; i <= n&&i <= m; i++) {
        v.push_back(i);
        DFS(n, m - i, v, i + 1);
        v.pop_back();
    }
}
int main()
{
    int n,m;
    while(cin>>n>>m){
        vector<int> v;
        if(n>m){
            n=m;
        }
        DFS(n,m,v,1);
    }
    return 0;
}