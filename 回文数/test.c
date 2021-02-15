bool isPalindrome(int x){
     if(x<0||x%10==0&&x!=0){//当x<0或x末尾为0时，都不是回文数
         return false;
     }
     int num=0;
     while(x>num){//将末尾一半的数找出来并与原数的一半进行比较
         num=num*10+x%10;
         x/=10;
     }
    return x==num||x==num/10;
}