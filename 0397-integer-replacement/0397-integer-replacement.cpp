class Solution {
public:
    int solve(long long n){
        if(n==1)return 0;
        int result = INT_MAX;
        if(n%2){
            result = min(result,1+solve(n+1));
            result = min(result,1+solve(n-1));
        }else{
            result = min(result,1+solve(n/2));
        }

        return result;
    }
    int integerReplacement(int n) {
        return solve(n);
    }
};