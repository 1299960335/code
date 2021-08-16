class Solution {
public:
    int candy(vector<int>& arr) {
        int up = 0,down = 0,top = 1,size = 1;
        for(int i = 1;i < arr.size();i++){
            size++;
            if(arr[i] > arr[i - 1]){
                up++;
                size += up;
                down = 0;
                top = up + 1;
            }
            else if(arr[i] == arr[i - 1]){
                up = 0;
                top = 1;
                down = 0;
            }
            else{
                up = 0;
                size += down;
                down++;
                if(down >= top){
                    size++;
                }
            }
        }
        return size;
    }
};