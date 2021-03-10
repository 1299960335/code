#include<stdio.h>
#include<string.h>
int Month[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},//定义一个二维数组，第一组为平年，第二组为闰年天数。
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int Year[2]={365,366};//记录年份天数


int main(){
    int year,month,day,number,a;
    scanf("%d",&a);//输入m值
    while(a--){
            scanf("%d%d%d%d",&year,&month,&day,&number);
        int y;
        if((year%4==0&&year%100!=0)||(year%400==0)){//判断是否为闰年
            y=1;
        }else y=0;
        for(int i=0;i<month;i++){
            number+=Month[y][i];//计算当前日期的天数
        }
        number+=day;
        month=0;
        if(number >Year[y]){//如果大于一年天数，年份增加
            year++;
            number-=Year[y];
            if((year%4==0&&year%100!=0)||(year%400==0)){
            y=1;
        }else y=0;
        }
        while(number>Month[y][month]){
            number -=Month[y][month];//计算月份
            month++;
        }
        day=number ;
        printf("%04d-%02d-%02d\n",year,month,day);
    }


    return  0;
}
