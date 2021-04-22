#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char choice(int M)
{
	char tmp = '0';
	switch (M)
	{
	case 10:
		tmp = 'A';
		break;
	case 11:
		tmp = 'B';
		break;
	case 12:
		tmp = 'C';
		break;
	case 13:
		tmp = 'D';
		break;
	case 14:
		tmp = 'E';
		break;
	case 15:
		tmp = 'F';
		break;
	default:
		tmp = (M + '0');
		break;
	}
	return tmp;
}

int main()
{
	int num = 0;
	int N = 0;
	cin >> num;
	cin >> N;
	string s;
	size_t M = num;
	//加负号逻辑
	//int M = num;
	//if (M < 0) {
		//M = -M;
	//}
	while (M > N)
	{
		int tmp = 0;
		tmp = M % N;
		s += choice(tmp);
		M /= N;
	}
	s += choice(M);
	//若题目要求加负号
	//if (num < 0) {
		//s += '-';
	//}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}