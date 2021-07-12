class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
        vector<vector<int>> vv(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return DFS(grid,vv,i,j);
                }
            }
        }
        return 0;
    }
    int DFS(vector<vector<int>>& grid,vector<vector<int>>& vv,int i,int j){
        if(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1)
        return 1;
        if(grid[i][j]==0)
        return 1;
        if(vv[i][j]==1)
        return 0;
        vv[i][j]=1;
        return DFS(grid,vv,i+1,j)+DFS(grid,vv,i,j+1)+DFS(grid,vv,i-1,j)+DFS(grid,vv,i,j-1);
    }
};