#include<iostream>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n){
        if(n==0)
            break;
        int conut=0;
        while(n>1){
            conut++;
            n=n/3+(n%3>0);
        }
        cout<<conut<<endl;
    }
    return 0;
}