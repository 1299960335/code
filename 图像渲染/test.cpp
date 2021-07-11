class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       if(image.empty())
       return image;
       int num=image[sr][sc];
       vector<vector<int>> vv(image.size(),vector<int>(image[0].size()));
       DFS(image,sr,sc,newColor,num,vv);
       return image;
    }
    void DFS(vector<vector<int>>& image,int r,int c,int newColor,int num,vector<vector<int>>& vv){
        if(r<0||r>image.size()-1||c<0||c>image[0].size()-1)
        return ;
        if(image[r][c]!=num)
        return ;
        if(vv[r][c]==1){
            return ;
        }
        image[r][c]=newColor;
        vv[r][c]=1;
        DFS(image,r-1,c,newColor,num,vv);
        DFS(image,r,c-1,newColor,num,vv);
        DFS(image,r+1,c,newColor,num,vv);
        DFS(image,r,c+1,newColor,num,vv);
    }
};