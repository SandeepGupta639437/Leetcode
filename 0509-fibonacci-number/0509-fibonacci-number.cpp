class MatrixExpo {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    using Matrix = vector<vector<ll>>;

    //-------------------------------------------------
    // Matrix Multiplication
    //-------------------------------------------------
    Matrix multiply(const Matrix &A, const Matrix &B) {

        int n = A.size();

        Matrix C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    //-------------------------------------------------
    // Identity Matrix
    //-------------------------------------------------
    Matrix identity(int n) {
        Matrix I(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) I[i][i] = 1;
        return I;
    }

    //-------------------------------------------------
    // Binary Exponentiation
    //-------------------------------------------------
    Matrix power(Matrix base, long long exp) {

        if (exp == 0) return identity(base.size());

        if (exp & 1) return multiply(base, power(multiply(base, base), exp >> 1));

        return power(multiply(base, base), exp >> 1);
    }

    //-------------------------------------------------
    // Matrix × Vector
    //-------------------------------------------------
    vector<ll> multiplyMatVec(const Matrix &A, const vector<ll> &v) {
        int n = A.size();
        vector<ll> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + A[i][j] * v[j]) % MOD;
            }
        }
        return res;
    }
};

class Solution {
public:
    using ll = long long;
    using Matrix = vector<vector<ll>>;
    int fib(int n) {

        if (n == 0) return 0;

        MatrixExpo obj;

        Matrix T = {
            {1, 1},
            {1, 0}
        };

        vector<long long> base = {1, 0};   // F1, F0

        Matrix P = obj.power(T, n - 1);

        vector<long long> ans = obj.multiplyMatVec(P, base);

        return ans[0];
    }
};