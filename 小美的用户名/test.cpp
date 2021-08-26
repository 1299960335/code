#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool judge(string& s)
{
    if(s.size() < 2){
        return false;
    }
    int num1 = 0;
    int num2 = 0;
    if((s[0] >='a'&& s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') ){
        for(int i = 0;i < s.size();i++){
            if((s[i] >='a'&& s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                num1++;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                num2++;
            }
            else{
                return false;
            }
        }
        if(num1 >= 1 && num2 >= 1){
            return true;
        }
    }
    return false;
}

int main()
{
    int num = 0;
    cin >> num;
    vector<string> vs;
    while(num--){
        string s;
        cin >> s;
        vs.push_back(s);
    }
    for(auto& e:vs){
        if(judge(e)){
            cout << "Accept" << endl;
        }
        else{
            cout << "Wrong"  << endl;
        }
    }
}