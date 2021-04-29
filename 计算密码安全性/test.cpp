#include<iostream>
#include<string>
using namespace std;
int word(string s, int& K) {
    int num = 0;
    int NUM = 0;
    int words = 0;
    for (auto e : s) {
        if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z')) {
            if (e >= 'a' && e <= 'z') {
                num++;
            }
            if (e >= 'A' && e <= 'Z') {
                NUM++;
            }
            words++;
        }
    }
    if (num != 0 && NUM != 0) {
        K = 1;
        return 20;
    }
    if (num == words|| NUM == words) {
        return 10;
    }
    return 0;
}
int numble(string s) {
    int cont = 0;
    for (auto e : s) {
        if (e >= '0' && e <= '9') {
            cont++;
        }
    }
    if (cont == 0)
        return 0;
    if (cont == 1)
        return 10;
    return 20;
}
int others(string s) {
    int cont = 0;
    for (auto e : s) {
        if (!((e >= '0' && e <= '9') || (e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))) {
            cont++;
        }
    }
    if (cont == 0)
        return 0;
    if (cont == 1)
        return 10;
    return 25;
}
void pinf(string& s2, int num) {
    if (num >= 90)
        s2 = "VERY_SECURE";
    else if (num >= 80)
        s2 = "SECURE";
    else if (num >= 70)
        s2 = "VERY_STRONG";
    else if (num >= 60)
        s2 = "STRONG";
    else if (num >= 50)
        s2 = "AVERAGE";
    else if (num >= 25)
        s2 = "WEAK";
    else
        s2 = "VERY_WEAK";
}
int main()
{
    string s;
    //while (cin >> s) {
    cin >> s;
        string s2 = "";
        int num = 0;
        if (s.size() <= 4) {
            num += 5;
        }
        else if (s.size() >= 5 && s.size() <= 7) {
            num += 10;
        }
        else {
            num += 25;
        }
        int i, j, k, K;
        K = 0;
        i = word(s, K);
        j = numble(s);
        k = others(s);
        num = num + i + j + k;
        if (i && j && k == 0)
            num += 2;
        if (i && j && k && K == 0)
            num += 3;
        if (i && j && k && K)
            num += 5;
        pinf(s2, num);
        cout << s2 << endl;
   // }
    return 0;
}