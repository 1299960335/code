class Solution {
public:
    int jumpFloorII(int number) {
      if(number<=1)
          return 1;
        int n=1;
        while(--number){
            n*=2;
        }
        return n;
   }
};