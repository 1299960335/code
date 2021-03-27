class Solution {
public:
    string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") {   //0乘任何数都是0
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto arr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {//转化为数字进行乘积运算
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                arr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {//将乘积结果放在数组中
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int num = arr[0] == 0 ? 1 : 0;
        string num3;
        while (num < m + n) {
            num3.push_back(arr[num]);//将数组中的元素转化为字符串
            num++;
        }
        for (auto &c: num3) {
            c += '0';
        }
        return num3;
    }
};