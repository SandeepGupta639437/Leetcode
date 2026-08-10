class MatrixExpo {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    using Matrix = vector<vector<ll>>;

    Matrix Multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<ll>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < n; k++) {
                if(A[i][k] == 0) continue;

                for(int j = 0; j < n; j++) {
                    if(B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix Identity(int n) {
        Matrix I(n, vector<ll>(n, 0));

        for(int i = 0; i < n; i++)
            I[i][i] = 1;

        return I;
    }

    Matrix Power(const Matrix& A, ll b) {
        if(b == 0)
            return Identity(A.size());

        if(b & 1)
            return Multiply(
                A,
                Power(Multiply(A, A), b >> 1)
            );

        return Power(Multiply(A, A), b >> 1);
    }

    vector<ll> multiplyMatVec(
        const Matrix& A,
        const vector<ll>& v
    ) {
        int n = A.size();

        vector<ll> result(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                result[i] =
                    (result[i] + A[i][j] * v[j]) % MOD;
            }
        }

        return result;
    }
};


class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    ll dp[20001][5];

    ll solve(int n, int ch) {
        if(n == 0) return 1;

        if(dp[n][ch] != -1) return dp[n][ch];

        ll ans = 0;

        if(ch == 0) {              // a -> e
            ans = solve(n-1, 1);
        }else if(ch == 1) {         // e -> a, i
            ans = (solve(n-1, 0) +
                   solve(n-1, 2)) % MOD;
        }else if(ch == 2) {         // i -> a,e,o,u
            ans = (solve(n-1, 0) + solve(n-1, 1) + solve(n-1, 3) + solve(n-1, 4)) % MOD;
        }else if(ch == 3) {         // o -> i,u
            ans = (solve(n-1, 2) +solve(n-1, 4)) % MOD;
        }else {                     // u -> a
            ans = solve(n-1, 0);
        }

        return dp[n][ch] = ans;
    }

    int countVowelPermutation(int n) {

        // Matrix T = {
        //     {0, 1, 1, 0, 1},
        //     {1, 0, 1, 0, 0},
        //     {0, 1, 0, 1, 0},
        //     {0, 0, 1, 0, 0},
        //     {0, 0, 1, 1, 0}
        // };

        // MatrixExpo matrixExpo;

        // Matrix result = matrixExpo.Power(T, n - 1);

        // vector<ll> ans = matrixExpo.multiplyMatVec( result,{1, 1, 1, 1, 1} );

        // ll total = 0;

        // for(int i = 0; i < 5; i++) {
        //     total = (total + ans[i]) % MOD;
        // }

        // return total;
        memset(dp,-1,sizeof(dp));
        ll ans = 0;

        for(int i = 0; i < 5; i++) {
            ans = (ans + solve(n-1, i)) % MOD;
        }

        return ans;
    }
};