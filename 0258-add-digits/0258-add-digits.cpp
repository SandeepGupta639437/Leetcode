class Solution {
public:
    int solve(int num){
        int temp = 0;
        while(num){
            temp = temp + num%10;
            num/=10;
        }
        return temp;
    }
    int addDigits(int num) {
        while(num>9){
            num = solve(num);
        }
        return num;
    }
};