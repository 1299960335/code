#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1;
	getline(cin, s1);
	string s2;
	size_t size=0;
	size_t begin=0;
	size_t end=0;
	while (size < s1.size()) {
		if (s1[size] >= '0' && s1[size] <= '9') {
			begin = size;
			while (size < s1.size() &&s1[size] >= '0' && s1[size] <= '9') {
				size++;
				end=size;
			}
			int len = end - begin;
			if (len > s2.size()) {
				s2 = s1.substr(begin,len);
			}
		}
		size++;
	}
	for (auto e : s2) {
		cout << e;
	}
	cout << endl;
	return 0;
}