class Solution {
public:
    static constexpr long long MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);

            exp >>= 1;
        }

        return res;
    }

    vector<long long> multiplyVec(
        const Matrix& A,
        const vector<long long>& v
    ) {
        int n = A.size();

        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;

            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        if (n == 1) return m;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        for (int x = 0; x < m; x++) {

            int upState = m + x;
            int downState = x;

            for (int y = x + 1; y < m; y++) {
                T[y][upState] = 1;
            }

            for (int y = 0; y < x; y++) {
                T[m + y][downState] = 1;
            }
        }

        Matrix P = power(T, n - 1);

        vector<long long> startUp(S, 0);
        vector<long long> startDown(S, 0);

        for (int x = 0; x < m; x++) {
            startUp[m + x] = 1;
            startDown[x] = 1;
        }

        auto A = multiplyVec(P, startUp);
        auto B = multiplyVec(P, startDown);

        long long ans = 0;

        for (long long x : A)
            ans = (ans + x) % MOD;

        for (long long x : B)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};