#include<iostream>
#include<algorithm>
using namespace std;
int count(int n){
    int size=0;
    for(int i=1;i<n;i++){
        int num=1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                num+=j;
                num=num+i/j;
            }
        }
        if(num==i){
            size++;
        }
    }
    return size-1;
}
int main()
{
    int num=0;
    while(cin>>num){
        int n=count(num);
        cout<<n<<endl;
    }
    return 0;
}