class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> nonZeroCount(n, 0);
        vector<long long> numUpTo(n, 0);
        vector<long long> digitSumUpTO(n, 0);
        vector<long long> pow10(n+1, 0);

        pow10[0] = 1;

        for(int i=1;i<=n;i++){
            pow10[i]  = (pow10[i-1]*10)%MOD;
        }

        if(s[0] != '0')nonZeroCount[0] = 1;

        for(int i=1;i<n;i++){
            nonZeroCount[i]  = (nonZeroCount[i-1] + ((s[i] != '0')?1:0))%MOD;
        }
        numUpTo[0] = s[0] -'0';

        for(int i=1;i<n;i++){
            if(s[i] != '0'){
                numUpTo[i] = (numUpTo[i-1] * 10 + s[i]-'0')%MOD;
            }else numUpTo[i] = numUpTo[i-1];
        }
        digitSumUpTO[0] = s[0] -'0';

        for(int i=1;i<n;i++){
            digitSumUpTO[i] = (digitSumUpTO[i-1] + s[i]-'0')%MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            long long sum = digitSumUpTO[r] - ((l==0) ?  0 : digitSumUpTO[l-1]);
            int k =  nonZeroCount[r] - ((l==0) ? 0 :nonZeroCount[l-1]);

            long long num = (numUpTo[r] - ((((l==0) ? 0 : numUpTo[l-1])) * pow10[k]  % MOD )+ MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};