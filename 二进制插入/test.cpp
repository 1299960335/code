#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    vector<string> v;
    int i = 0;
    while (i < v.size()) {
        int head = 0;
        int last = s.find(" ", i);
        string s2;
        if (last != s.npos && s[head] != '"') {
            s2 = s.substr(head, last - head);
        }
        else if (last != s.npos) {
            last = s.find('"', last);
            s2 = s.substr(head, last - head);
        }
        else {
            s2 = s.substr(head);
        }
        v.push_back(s2);
    }
    for (auto e : v) {
        cout << e << endl;
    }
    return 0;
}