#include<iostream>
using namespace std;

int main()
{
    double n;
    while(cin>>n){
        double r=0;
        cin>>r;
        double l=2*r*3.14;
        if(l>=n){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}