#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool judge(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return false;
    }
    return true;
}
int main()
{
    
    int num=0;
    while(cin>>num){
        int size=num/2;
        int j=size;
        int k=size;
        int i=0;
        while(i<size){
            if(j>=2&&judge(j)&&judge(k)){
                cout<<j<<endl;
                cout<<k<<endl;
                break;
            }
            j--;
            k++;
            i++;
        }
    }
    return 0;
}