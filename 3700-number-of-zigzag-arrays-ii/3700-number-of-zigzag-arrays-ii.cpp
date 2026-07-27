using ll = long long;
const ll MOD = 1e9+7;
using Matrix =  vector<vector<ll>>;

class MatrixExpo{
public:

  Matrix Multiply(const Matrix& A, const Matrix& B){
    int n = A.size();

    Matrix C(n,vector<ll>(n,0));

    for(int i=0;i<n;i++){
      for(int k=0;k<n;k++){
        if(A[i][k]==0)continue;
        for(int j=0;j<n;j++){
          if(B[k][j]==0)continue;
          C[i][j] = (C[i][j] + A[i][k] * B[k][j])%MOD;
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
        result[i] = (result[i] + A[i][j] * v[j]) % MOD;
      }
    }
    return result;
  }
};


class Solution {
public:

    int zigZagArrays(long long n,int l,int r){

        MatrixExpo mt;

        int M=r-l+1;

        int SZ=2*M;

        Matrix T(SZ,vector<ll>(SZ,0));

        // dp[][val][0] = sum(dp[][k][1]), k<val
        for(int val=1;val<=M;val++)
            for(int k=1;k<val;k++)
                T[val-1][M+k-1]=1;

        // dp[][val][1] = sum(dp[][k][0]), k>val
        for(int val=1;val<=M;val++)
            for(int k=val+1;k<=M;k++)
                T[M+val-1][k-1]=1;

        // Base layer (i = n-1)
        vector<ll> base(SZ,1);

        Matrix P=mt.Power(T,n-1);

        vector<ll> state=mt.multiplyMatVec(P,base);

        ll ans=0;

        for(ll x:state)
            ans=(ans+x)%MOD;

        return ans;
    }
};