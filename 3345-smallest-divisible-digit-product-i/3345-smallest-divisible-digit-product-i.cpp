class Solution {
public:
    int proSum(int n){
        int sum = 1;
        while(n){
            sum *= n%10;
            n/=10;
        }
        return sum;
    }
    int smallestNumber(int n, int t) {
        int i =n;
        while(i<n+11){
            if(proSum(i)%t==0)return i;
            i++;
        }
        return 0;
    }
};