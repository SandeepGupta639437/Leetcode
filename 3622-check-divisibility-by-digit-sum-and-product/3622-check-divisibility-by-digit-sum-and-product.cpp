class Solution {
public:
    int summing(int n){
        int sum = 0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int producting(int n){
        int sum = 1;
        while(n){
            sum*=n%10;
            n/=10;
        }
        return sum;
    }
    bool checkDivisibility(int n) {
        int x = summing(n);
        int y = producting(n);

        return (n%(x+y)==0);
    }
};