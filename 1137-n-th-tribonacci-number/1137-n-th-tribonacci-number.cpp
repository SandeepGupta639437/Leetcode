class MatrixExpo{
public:
    using ll = long long;
    using Matrix =  vector<vector<ll>>;

  Matrix Multiply(const Matrix& A, const Matrix& B){
    int n = A.size();

    Matrix C(n,vector<ll>(n,0));

    for(int i=0;i<n;i++){
      for(int k=0;k<n;k++){
        if(A[i][k]==0)continue;
        for(int j=0;j<n;j++){
          if(B[k][j]==0)continue;
          C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
        }
      }
    }
    return C;
  }

  Matrix Identity(int n){
    Matrix I(n,vector<ll>(n,0));
    for(int i=0;i<n;i++)I[i][i] = 1;
    return I;
  }

  Matrix Power(const Matrix& A, ll b) {
    if (b == 0) return Identity(A.size());
    if (b & 1) return Multiply(A, Power(Multiply(A, A), b >> 1));
    return Power(Multiply(A, A), b >> 1);
  }

  vector<ll> multiplyMatVec(const Matrix& A, const vector<ll>& v) {
    int n = A.size();
    vector<ll> result(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        result[i] = (result[i] + A[i][j] * v[j]);
      }
    }
    return result;
  }
};

class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9+7;
    using Matrix =  vector<vector<ll>>;

    int tribonacci(int n) {
        Matrix T = {
            {1, 1 , 1},
            {1, 0 , 0},
            {0, 1 , 0}
        };

        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;

        MatrixExpo matrixExpo;

        Matrix result = matrixExpo.Power(T, n-2);

        vector<ll>ans = matrixExpo.multiplyMatVec(result, {1, 1, 0});

        return ans[0];
    }
};