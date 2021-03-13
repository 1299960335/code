#includebitsstdc++.h
using namespace std;
 
平年和闰年的各个月份每月的天数
int month[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31},
    {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};
 
判断是否为闰年
bool isLeap(int year){
    return ( year % 4 == 0 && year % 100 != 0 )  (year % 400 == 0);
}
 
int main() {
    int y1, y2, m1, m2, d1, d2;
    int date1, date2;
    int count = 1;
    while( scanf(%d%d, &date1, &date2) != EOF ){
        保证date1-date2是升序
        if(date1  date2){
            int temp = date1;
            date1 = date2;
            date2 = temp;
        }
        将年-月-日取出放到y-m-d中
        y1 = date1  10000; m1 = date1 % 10000  100; d1 = date1 % 100;
        y2 = date2  10000; m2 = date2 % 10000  100; d2 = date2 % 100;
        判断当年-月-日不相等时，加一直至相等
        while( y1  y2  m1  m2  d1  d2 ){
            d1 ++;  天数加1
            if(d1 == month[m1][isLeap(y1)] + 1){    天数加1后超过了y1年m1月的天数
                m1 ++;
                d1 = 1;
            }
            if(m1 == 13){
                y1 ++;
                m1 = 1;
            }
            count ++;
        }
        printf(%dn, count);
    }
    return 0;
}