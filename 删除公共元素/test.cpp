#include<iostream>
#include<string>
using namespace std;
int main()
{
string s1;
string s2;
getline(cin,s1);
getline(cin,s2);
if(s2.size()==0){
cout<<s1<<endl;
}
if(s1.size()<s2.size()){
cout<<endl;
}
int i=0;
string s3;
while(i<s2.size()){
for(int j=0;j<s1.size();j++){
if(s1[j]!=s2[i]){
s3+=s1[j];
}
}
s1=s3;
s3="";
i++;
}
cout<<s1<<endl;
return 0;
}