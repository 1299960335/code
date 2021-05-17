#include<iostream>
using namespace std;
int count(int n)
{
    int size=0;
    int num=0;
    while(n){
        if(n>=3){
            size=n%3;
            num=num+n/3;
            size=size+n/3;
        }
        else{
            break;
        }
        n=size;
        size=0;
    }
    if(n==2){
        num++;
    }
    return num;
    
}
int main()
{
    int n=0;
    while(cin>>n){
      int num=count(n);
        if(num!=0)
        cout<<num<<endl;
    }
    return 0;
}