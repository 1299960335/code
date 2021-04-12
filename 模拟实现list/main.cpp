#include"listh.h"
#include<iostream>
using namespace std;
int main()
{
	bite::list<int> v2;
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
    v2.push_back(1);
	v2.push_back(1);
	for (auto e : v2) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}