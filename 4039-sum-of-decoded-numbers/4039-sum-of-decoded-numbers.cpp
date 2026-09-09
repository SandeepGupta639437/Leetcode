class Solution {
public:
    #define ll long long
    const int M = 1e9+7;

    // pair<int, int> findXY(int width, ll d) {
    //     string s = to_string(d);

    //     string x = s.substr(0, width);
    //     string y = s.substr(width);

    //     return {stoi(x), stoi(y)};
    // }

    static constexpr uint64_t TENS[] = { 1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000,
        1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000 };

    ll modPow(ll a, ll b) {
        if (b == 0) return 1;

        a %= M;

        if (b & 1) return (a*modPow((a*a)%M, b/2)) % M;

        return modPow((a * a) % M, b / 2);
    }

    int sumDecoded(vector<long long>& nums) {
        int sum = 0;

        for(long long& it: nums){
            int w = it % 10;
            ll d = it/10;

            uint8_t o = 0;
            for ( ; TENS[o] <= d; o++) ;

            const uint64_t t = TENS[o-w];

            const uint64_t x = d / t, y = d % t;

            ll powerSum = (ll)modPow(x,y);
            sum = (sum + 1LL*powerSum)%M;
        }

        return sum;
    }
};