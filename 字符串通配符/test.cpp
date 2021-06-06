#include<iostream>
#include<string>
using namespace std;
int judge(string s1, string s2)
{
    int size1 = s1.size();
    int size2 = s2.size();
    int i = 0, j = 0;
    while ((i < size1) && (j < size2)) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        }
        else {
            if (s1[i] == '?') {
                i++;
                j++;
            }
            else if (s1[i] == '*') {
                i++;
                if (i < size1) {
                    if (s1[i] == s2[j]) {
                        j++;
                        i++;
                    }
                    j++;
                }
                else
                    break;
            }
            else
                return -1;
        }
    }
    if (i < size1 && (j == size2))
        return -1;
    return 0;
}
int main()
{
    string s1;
    string s2;
    while (cin >> s1) {
        cin >> s2;
        int num = judge(s1, s2);
        if (num == -1)
            cout << "false" << endl;
        else
            cout << "true" << endl;
    }
    return 0;
}