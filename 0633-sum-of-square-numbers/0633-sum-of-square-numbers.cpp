class Solution {
public:
    bool judgeSquareSum(int c) {
       long long n=sqrt(c);
       long long a=0;
       long long b=n; 
       while(true){
         if(a*a+b*b==c)return true;
         else if(a*a+b*b<=c) a++;
         else b--;
         if(a>n)return false;
       }
    }
};