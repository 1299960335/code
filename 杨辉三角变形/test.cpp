#include<iostream>
#include<vector>
using namespace std;
int find(int n)
{
    if (n <= 2)
        return -1;
    int i = 2;
    vector<int> v1 = { 1,1,1 };
    while (i != n) {
        int num = i * 2 - 1;
        vector<int> v2(num);
        v2[0] = 1, v2[v2.size() - 1] = 1;
        v2[1] = v1[0] + v1[1], v2[v2.size() - 2] = v1[v1.size() - 1] + v1[v1.size() - 2];
        for (int j = 2; j < v2.size() - 2; j++) {
            v2[j] = v1[j - 2] + v1[j - 1] + v1[j];
        }
        v1 = v2;
        i++;
    }
    for (int j = 0; j < v1.size(); j++) {
        if (v1[j] % 2 == 0)
            return j + 1;
    }
    return -1;
}

int main()
{
    int n = 0;
    while (cin >> n) {
        int num = find(n);
        cout << num << endl;
    }
    return 0;
}