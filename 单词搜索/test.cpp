class Solution {
public:
     bool judge(vector<vector<char>>& board,int i,int j,string& word,int num)
     {
        if(num >= word.size()){
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
            return false;
        }
        if(board[i][j] != word[num]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '.';
        bool size = judge(board,i + 1,j,word,num + 1) || \
            judge(board,i - 1,j,word,num + 1) || \
            judge(board,i,j + 1,word,num + 1) || \
            judge(board,i,j - 1,word,num + 1);
         if(size){
             return true;
         }
         board[i][j] = temp;
        return size;
    }
    bool exist(vector<vector<char> > &board, string word) {
        bool num = true;
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                if(board[i][j] == word[0]){
                    int size = 0;
                     num = judge(board,i,j,word,size);
                    if(num){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};