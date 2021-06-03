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
            size_t j = s1.find(s2, i);
            if (j != s1.npos) {
                i = j + s2.size();
                num++;
            }
            else {
                break;
            }
        }
        cout << num << endl;
    }
    return 0;
}