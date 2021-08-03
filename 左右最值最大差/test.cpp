class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        int max=A[0];
        for(int i=0;i<n;i++){
            if(max<A[i]){
                max=A[i];
            }
        }
        int num=0;
        if(A[0]>A[n-1]){
            num=max-A[n-1];
        }
        else{
            num=max-A[0];
        }
        return num;
    }
};