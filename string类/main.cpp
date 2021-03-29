#include"Str.h"
int main()
{
	bit::string s1("asdfgh");
	bit::string s2(s1);
	bit::string s3 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	s1 += "zxvv";
	cout << s1 << endl;
	return 0;
}