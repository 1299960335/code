#include"date.h"

int Date::GetMonthDay(int year, int month) 
{
	static int daysArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//�����µ�����
	int days = daysArr[month];
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))) {
		days = 29;//������������
	}
	return days;
}
Date ::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year >= 0 && month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month))) {
		cout << "���ڷǷ�" << endl;
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
	if (day < 0) {     //�������˴�������-100�����ֵ
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {//������ڵ�ǰ�µ�������
		_day -= GetMonthDay(_year, _month);//��++�����ȥ��ǰ�µ�����
		_month++;                          //���´���12������++������Ϊ1
		if (_month == 13) {
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date ret(*this);//��������
	ret += day;//���������
	return ret;
}
Date& Date::operator-=(int day)
{
	if (day < 0) {
		return *this += -day;
	}
	_day -= day;
	while (_day < 1) {
		_day += GetMonthDay(_year, _month - 1);//���������������С��1��
		_month--;                              //˵����ǰ�²�������
		if (_month == 0) {                     //��ʱ��ǰһ���½�������������
			_year--;                           //���·ݵ�0��
			_month = 12;                       //��-=1������Ϊ12
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
//Ϊ�˺�ǰ��++�����Ȳ������������һ���βΣ����������ʹ�ã�������ǰ��++���ɺ�������
Date Date::operator++(int)
{
	Date ret(*this);//ǰ��++,��ʹ����++
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
inline bool Date::operator >= (const Date& d)//���븴��
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
	while (min != max) {//��С������ļӣ��Ӷ�������ǲ������
		++n;
		++min;
	}
	return n * flag; 
}