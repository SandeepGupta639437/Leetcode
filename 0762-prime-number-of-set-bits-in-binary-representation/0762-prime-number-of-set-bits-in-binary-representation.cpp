class Solution {
public:
    bool prime(int s){
        if(s==1)return false;
        if(s==2)return true;
        for(int i=2;i<=sqrt(s);i++){
            if(s%i==0)return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int setbit=__builtin_popcount(i);
            if(prime(setbit))ans++;
        }
        return ans;
    }
};