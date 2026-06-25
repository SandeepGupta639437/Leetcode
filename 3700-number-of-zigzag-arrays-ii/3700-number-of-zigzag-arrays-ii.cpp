class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    using Matrix = vector<vector<ll>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<ll>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < n; k++) {

                if(A[i][k] == 0) continue;

                for(int j = 0; j < n; j++) {

                    if(B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix result(n, vector<ll>(n, 0));

        for(int i = 0; i < n; i++)
            result[i][i] = 1;

        while(exp) {

            if(exp & 1)
                result = multiply(result, base);

            base = multiply(base, base);

            exp >>= 1;
        }

        return result;
    }

    vector<ll> multiplyMatVec( const Matrix& A , const vector<ll>& v ) {
        int n = A.size();

        vector<ll> res(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(A[i][j] == 0) continue;

                res[i] = (res[i] + A[i][j] * v[j]) % MOD;
            }
        }

        return res;
    }

    int zigZagArrays(long long n, int l, int r) {

        int M = r - l + 1;

        if(n == 1)
            return M;

        int SZ = 2 * M;

        Matrix T(SZ, vector<ll>(SZ, 0));

        // U(j) = sum_{k<j} D(k)
        for(int j = 1; j <= M; j++) {
            for(int k = 1; k < j; k++) {
                T[j - 1][M + (k - 1)] = 1;
            }
        }

        // D(j) = sum_{k>j} U(k)
        for(int j = 1; j <= M; j++) {
            for(int k = j + 1; k <= M; k++) {
                T[M + (j - 1)][k - 1] = 1;
            }
        }

        /*
            Base layer:
            length = 2

            U(j) = count(k < j) = j-1
            D(j) = count(k > j) = M-j
        */

        vector<ll> base(SZ, 0);

        for(int j = 1; j <= M; j++) {
            base[j - 1] = j - 1;
            base[M + j - 1] = M - j;
        }

        Matrix P = power(T, n - 2);

        vector<ll> finalState =
            multiplyMatVec(P, base);

        ll ans = 0;

        for(ll x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};