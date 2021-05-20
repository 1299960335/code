#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int num=0;
    while(cin>>num){
        string s;
        cin>>s;
        vector<int> v1;
        int biao=1;
        if(num<=4){
            for(int i=1;i<num+1;i++){
                v1.push_back(i);
            }
            for(int i=0;i<s.size();i++){
                if(s[i]=='U'){
                    if(biao==1)
                        biao=v1.size();
                    else
                        biao--;
                }
                else{
                     if(biao==v1.size())
                         biao=1;
                    else
                        biao++;
                }
            }
        }
        else{
            v1={0,0,0,0};
            vector<int> v2;
            for(int i=1;i<num+1;i++){
                v2.push_back(i);
            }
            for(int i=0;i<4;i++){
                v1[i]=i+1;
            }
            for(int i=0;i<s.size();i++){
                if(s[i]=='U'){
                    if(biao==1){
                        biao=v2.size();
                        int size=biao-4+1;
                        for(int i=0;i<v1.size();i++){
                            v1[i]=size;
                            size++;
                        }
                    }
                    else{
                        biao--;
                        if(biao<v1[0]){
                            int size=biao;
                            for(int i=0;i<v1.size();i++){
                                v1[i]=size;
                                size++;
                            }
                        }
                    }
                }
                else{
                    if(biao==v2.size()){
                        biao=1;
                        int size=1;
                        for(int i=0;i<v1.size();i++){
                            v1[i]=size;
                            size++;
                        }
                    }
                    else{
                        biao++;
                        if(biao>v1[v1.size()-1]){
                            int size=biao;
                            for(int i=v1.size()-1;i>=0;i--){
                                v1[i]=size;
                                size--;
                            }
                        }
                    }
                }
            }
        }
        for(auto& e:v1){
            cout<<e<<" ";
        }
        cout<<endl;
        cout<<biao<<endl;
    }
    return 0;
}