#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n){
        if(n==0)
            continue;
        long long num1=pow(5,n)-4;
        long long num2=pow(4,n)+n-4;
        cout<<num1<<" "<<num2<<endl;
    }
    return 0;
}