#include <iostream>
using namespace std;
int num(int n){
    int month1=1,month2=0,month3=0;
    while(--n){
         month3+=month2;
         month2=month1;
         month1=month3;
    }
    return month1+month2+month3;
}
int main(){
    int m;
    while(cin>>m){
        int size=num(m);
        cout<<size<<endl;
    }
}