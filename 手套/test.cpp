class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int num1=0;
        int num2=0;
        int gloves=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(left[i]*right[i]==0)
                gloves=gloves+right[i]+left[i];
            else{
                v.push_back(i);
                num1+=left[i];
                num2+=right[i];
            }
        }
        if(num1>num2){
            int min =right[v[0]];
            for(int i=0;i<v.size();i++){
                if(right[v[i]]<=min){
                    min=right[v[i]];
                }
            }
            gloves=gloves+num2-min+1;
            gloves+=1;
        }
        else{
            int min =right[v[0]];
            for(int i=0;i<v.size();i++){
                if(left[v[i]]<=min){
                    min=left[v[i]];
                }
            }
            gloves=gloves+num1-min+1;
            gloves+=1;
        }
        return gloves;
    }
};