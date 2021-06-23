#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n){
        int size=0;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                }
                size++;
            }
        }
        if(n>1){
            size++;
        }
        cout<<size<<endl;
    }
    return 0;
}