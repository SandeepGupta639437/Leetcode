class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        
        int original = x;
        int reversed = 0;

        while(x){
            reversed = 1LL*reversed*10 + x%10;
            x/=10;
        }

        return (original==reversed);
    }
};