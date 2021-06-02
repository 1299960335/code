#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    while (cin >> s1) {
        string s2;
        cin >> s2;
        int num = 0;
        int i = 0;
        while (i < s1.size()) {
            if (s1.find(s2, i) != s1.npos) {
                num++;
                i = s1.find(s2) + s2.size();
            }
            else {
                break;
            }
        }
        cout << num << endl;
    }
    return 0;
}