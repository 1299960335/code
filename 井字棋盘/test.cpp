#include<iostream>
using namespace std;
int gezi(int m,int n)
{
if(n==0)
return 1;
if(m==0)
return 1;
return gezi(m-1,n)+gezi(m,n-1);
}
int main()
{
int n=0;
int m=0;
while(cin>>n>>m)
{
int num=0;
num=gezi(m,n);
cout<<num<<endl;
}
return 0;
}