class Solution {
public:
    int firstUniqChar(string s) {
      int arr[26]={0};
      int i=s.size();
      for(int j=0;j<i;j++){
          arr[s[j]-'a']++;
      }
      for(int j=0;j<i;j++){
          if(arr[s[j]-'a']==1){
              return j;
          }
      }
      return -1;
    }
};