#include"date.h"

int Date::GetMonthDay(int year, int month) 
{
	static int daysArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//储存月的天数
	int days = daysArr[month];
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))) {
		days = 29;//考虑闰年的情况
	}
	return days;
}
Date ::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year >= 0 && month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month))) {
		cout << "日期非法" << endl;
	}
}
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
Date& Date::operator+=(int day)
{
	if (day < 0) {     //考虑有人存在输入-100天等数值
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {//如果大于当前月的天数，
		_day -= GetMonthDay(_year, _month);//月++，天减去当前月的天数
		_month++;                          //若月大于12，则年++，月置为1
		if (_month == 13) {
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date ret(*this);//拷贝构造
	ret += day;//运算符重载
	return ret;
}
Date& Date::operator-=(int day)
{
	if (day < 0) {
		return *this += -day;
	}
	_day -= day;
	while (_day < 1) {
		_day += GetMonthDay(_year, _month - 1);//如果减下来的天数小于1，
		_month--;                              //说明当前月不够减，
		if (_month == 0) {                     //此时向前一个月借天数进行运算
			_year--;                           //若月份到0，
			_month = 12;                       //年-=1，月置为12
		}
	}
	return *this;
}
Date Date::operator-(int day) 
{
	Date ret(*this);
	ret -= day;
	return ret;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//为了和前置++区别，迫不得已这里加了一个形参，这个参数不使用，仅仅与前置++构成函数重载
Date Date::operator++(int)
{
	Date ret(*this);//前置++,先使用再++
	*this += 1;
	return ret;
}
Date Date:: operator--(int) 
{
	Date ret(*this);
	*this -= 1;
	return ret;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year) {
		return true;
	}
	else if (_year == d._year) {
		if (_month > d._month) {
			return true;
		}
		else if (_month == d._month) {
			if (_day > d._day) {
				return true;
			}
		}
	}
	return false;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
inline bool Date::operator >= (const Date& d)//代码复用
{
	return *this > d || *this == d;
}
bool  Date::operator < (const Date& d)
{
	return !(*this >= d);
}
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
bool Date::operator != (const Date& d) 
{
	return !(*this == d);
}
int Date::operator-(const Date& d)
{
	Date max = *this, min = d;
	int flag = 1;
	if (*this < d) {
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max) {//让小的往大的加，加多少天就是差多少天
		++n;
		++min;
	}
	return n * flag; 
}