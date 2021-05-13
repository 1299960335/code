#include<iostream>
#include<string>
using namespace std;
bool judge(string& s)
{
    int num=s.find(' ');
    string s1=s.substr(0,num);
    if(s1=="JOKER"||s1=="joker"){
        string s2=s.substr(num+1);
        if(s2!=s1&&(s2=="joker"||s2=="JOKER"))
            return true;
    }
    int j=1;
    while(num<s.size()){
        int size=s.find(' ',num+1);
        string s2=s.substr(num+1,size-num-1);
        if(s1!=s2){
            return false;
        }
        j++;
        num=size;
    }
    if(j==4)
    return true;
    return false;
}
bool cont(string& s, int& size)
{
    int num = s.find(' ');
    string s1 = s.substr(0, num);
    int i = num;
    int k = 1;
    while (num < s.size()) {
        int j = s.find(' ', num + 1);
        string s2 = s.substr(num + 1, j - num - 1);
        if (s1 != s2) {
            return false;
        }
        k++;
        num = j;
    }
    size = k;
    return true;
}
bool shun(string&s)
{
    if(s.size()==5){
        return true;
    }
    return false;
}
int main()
{
    string s="345678910JQKA2";
    string s1;
    while(getline(cin,s1)){
        string s2;
        string s3;
        size_t num =s1.find('-');
        s2=s1.substr(0,num);
        s3=s1.substr(num+1);
        if(!(judge(s2))&&!(judge(s3))){
            int size1=0;
            int size2=0;
            if(!(cont(s1,size1))&&!(cont(s2,size2))){
                if(!(shun(s2))&&!(shun(s3))){
                    if((s2!="joker"&&s2!="JOKER")&&(s3!="joker"&&s3!="JOKER")){
                        if(s.find(s2[0])>s.find(s3[0]))
                            cout<<s2<<endl;
                        else
                            cout<<s3<<endl;
                    }
                    else{
                        if(s2=="joker"&&s3!="JOKER")
                            cout<<s2<<endl;
                        else if(s2=="JOKER")
                            cout<<s2<<endl;
                        else
                            cout<<s3<<endl;
                    }
                }
                else if((!(shun(s2))&&shun(s3))||(shun(s2)&&!(shun(s3)))){
                    cout<<"ERROR"<<endl;
                }
                else{
                    if(s.find(s2[0])>s.find(s3[0]))
                        cout<<s2<<endl;
                    else
                        cout<<s3<<endl;
                }
            }
            else if((!(cont(s2,size1))&&cont(s3,size2))||(cont(s2,size1)&&!(cont(s3,size2))))
                cout<<"ERROR"<<endl;
            else{
                    if(size1!=size2)
                        cout<<"ERROR"<<endl;
                    else{
                        if(s.find(s2[0])>s.find(s3[0]))
                            cout<<s2<<endl;
                        else
                            cout<<s3<<endl;
                    }
            }
        }
        else{
            if(judge(s2)&&!(judge(s3)))
               cout<<s2<<endl;
            else if(!(judge(s2))&&judge(s3))
                cout<<s3<<endl;
            else{
                if(s2=="joker JOKER"||s2=="JOKER joker")
                    cout<<s2<<endl;
                else if(s3=="joker JOKER"||s3=="JOKER joker")
                    cout<<s3<<endl;
                else{
                    if(s.find(s2[0])>s.find(s3[0]))
                        cout<<s2<<endl;
                    else
                        cout<<s3<<endl;
                }
            }
        }
    }
    return 0;
}