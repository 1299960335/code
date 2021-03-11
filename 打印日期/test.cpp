#include<iostream>
using namespace std;
int _month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int year;
    int numble;
    while(cin>>year>>numble){
        if((year%4==0)&&(year%100!=0)||(year%400==0)){
            _month[2]=29;
        }
        int month=0;
        int day=0;
        for(int i=0;i<13;i++){
            if(numble>_month[i]){
                numble-=_month[i];
                month++;
            }
            else{
                   if(numble==0){
                day=_month[i];
                    break;
            }
            else{
                day=numble;
                break;
            }
            }
        }

        printf("%d-%02d-%02d",year,month,day);
    }
    return 0;
}