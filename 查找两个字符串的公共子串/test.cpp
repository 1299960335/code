#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s1;
    string s2;
    while(cin>>s1){
        cin>>s2;
        int size1=s1.size();
        int size2=s2.size();
        if(s1.size()>s2.size()){
            s1.swap(s2);
           size1=s1.size();
           size2=s2.size();
        }
        vector<vector<int>> vv(size1+1,vector<int>(size2+1,0));
        int max=0;
        string s3;
        for(int i=1;i<size1;i++){
            for(int j=1;j<size2;j++){
                if(s1[i-1]==s2[j-1]){
                    vv[i][j]+=vv[i-1][j-1];
                    vv[i][j]+=1;
                }
                if(vv[i][j]>max){
                    max=vv[i][j];
                    s3=s1.substr(i-max,max);
                }
            }
        }
        cout<<s3<<endl;
        
    }
    return 0;
}