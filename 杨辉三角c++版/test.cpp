class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v1;
        v1.resize(numRows);
        for(size_t i=1;i<numRows+1;i++){
            v1[i-1].resize(i,0);
            v1[i-1][0]=1;
            v1[i-1][i-1]=1;
        }
       for(size_t i=0;i<v1.size();i++){
           for(size_t j=0;j<v1[i].size();j++){
                if(v1[i][j]==0){
                    v1[i][j]=v1[i-1][j]+v1[i-1][j-1];
               }           
           }
       }
       return v1;
    }
};