#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s1;
    string s2;
    while (cin >> s1) {
        cin >> s2;
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int cont = 0;
        string s3;
        while ((j >= 0) && (i >= 0)) {
            int num = s1[i] - '0' + s2[j] - '0' + cont;
            if (num >= 10) {
                char c = num - 10 + '0';
                s3 += c;
                cont = 1;
            }
            else {
                char c = num + '0';
                s3 += c;
                cont = 0;
            }
            j--;
            i--;
        }
        if ((i >= 0) && (j < 0)) {
            while (i >= 0) {
                int num = s1[i] - '0' + cont;
                if (num >= 10) {
                    char c = num - 10 + '0';
                    s3 += c;
                    cont = 1;
                }
                else {
                    char c = num + '0';
                    s3 += c;
                    cont = 0;
                }
                i--;
            }
        }
        else if ((j >= 0) && (i < 0)) {
            while (j >= 0) {
                int num = s2[j] - '0' + cont;
                if (num >= 10) {
                    char c = num - 10 + '0';
                    s3 += c;
                    cont = 1;
                }
                else {
                    char c = num + '0';
                    s3 += c;
                    cont = 0;
                }
                j--;
            }
        }
        if (cont == 1) {
            s3 += '1';
        }
        reverse(s3.begin(), s3.end());
        cout << s3 << endl;
    }
    return 0;
}