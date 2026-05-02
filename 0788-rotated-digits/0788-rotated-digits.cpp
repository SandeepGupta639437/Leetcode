class Solution {
public:
    bool check(int n){
        bool changed = false;
        while(n>0){
            int d = n%10;
            n/=10;
            if(d==3 ||d==4 || d==7)return false;
            if(d==2 || d==5 || d==9 || d==6)changed = true;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(check(i))ans++;
        }
        return  ans;
    }
};