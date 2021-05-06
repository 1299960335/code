#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int num=0;
    while(cin>>num){
        int size=8;
        int count=0;
        while(size>0){
            int i=1;
            i=num&i;
            if(i==1){
                count++;
            }
            else{
                v.push_back(count);
                count=0;
            }
            size--;
            num=num>>1;
        }
        v.push_back(count);
        int a=v[0];
        for(int i=0;i<v.size();i++){
            if(v[i]>a){
                a=v[i];
            }
        }
        cout<<a<<endl;
        v={0};
    }
    return 0;
}