class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        vector<vector<int>> vv(7,vector<int>(7,0));
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                vv[i][j]=board[i-1][j-1];
            }
        }
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){
                int num1=vv[i][j]+vv[i-1][j];
                int num2=vv[i][j]+vv[i][j-1];
                if(num1>num2){
                    vv[i][j]=num1;
                }
                else{
                    vv[i][j]=num2;
                }
            }
        }
        return vv[6][6];
    }
};