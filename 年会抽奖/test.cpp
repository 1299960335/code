#include<iostream>
#include<string>
using namespace std;
int main()
{
    long long arr1[21]={0,0,1};
    long long arr2[21]={0,1,2};
    for(int i=3;i<21;i++){
        arr1[i]=(i-1)*(arr1[i-1]+arr1[i-2]);
        arr2[i]=i*arr2[i-1];
    }
    int n=0;
    while(cin>>n){
        printf("%4.2lf%%\n",100*double(arr1[n])/arr2[n]);
    }
    return 0;
}