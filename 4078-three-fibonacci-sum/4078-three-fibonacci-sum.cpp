class Solution {
public:
    bool threeFibonacciSum(int n) {
        int x1 = 0, x2 = 1, x3 = 1;
        for(int i=0;true;i++){
            if(x1+x2+x3==n)return true;
            if(x1+x2+x3>n)return false;
            x1 = x2;
            x2 = x3;
            x3 = x1+x2;
        }
        return false;
    }
};