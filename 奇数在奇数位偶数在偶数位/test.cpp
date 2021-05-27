    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int i=0;
        int j=1;
        int end=len-1;
        while(i<len&&j<len){
            if(arr[end]%2==0){
                swap(arr[i],arr[end]);
                i+=2;
            }
            if(arr[end]%2!=0){
                swap(arr[j],arr[end]);
                j+=2;
            }
        }
    }