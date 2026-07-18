class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        long long y = 10;
        while(n){
            int d = n%y;
            if(d!=0)ans.push_back(d);
            n = n/y;
            n*=y;
            if(n)y=1LL*10*y;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};