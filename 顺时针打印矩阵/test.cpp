class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> push;
       if(matrix.empty()||matrix[0].empty()){
           return push;
       }
       vector<vector<int>> v(matrix.size(),vector<int>(matrix[0].size()));
       int dx[4]={0,1,0,-1};//用来改变方向
       int dy[4]={1,0,-1,0};
       int m=matrix.size(),n=matrix[0].size();
       int x=0,y=0,d=0;
       for(int i=0;i<m*n;i++){
           if(v[x][y]!=1){
               push.push_back(matrix[x][y]);
               v[x][y]=1;
           }
           int a=x+dx[d];
           int b=y+dy[d];
           if(a<0||a>=m||b<0||b>=n||v[a][b]){//判断是否需要改变方向
               d=(d+1)%4;
               a=x+dx[d],b=y+dy[d];
           }
           x=a,y=b;
       }
       return push;
    }
};