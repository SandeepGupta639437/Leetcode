class Fancy {
public:
   typedef long long ll;

   ll MOD = 1e9+7;
   vector<ll > seq;
   ll  add = 0;
   ll mult =1;
   // find power with the help of Binary Exponentiation for Fermat's Little Theorem -> power(mult,M-2);
    ll power(ll a, ll b){
        if(b==0)return 1;
        ll half = power(a,b/2);
        ll result = (half*half)%MOD;

        if(b%2)result = (result*a)%MOD;
        return result;
    }
    Fancy() {

        
    }
    
    void append(int val) {
        ll x = ((val - add)%MOD+MOD) *power(mult,MOD-2)%MOD;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add+inc)%MOD;
    }
    
    void multAll(int m) {
        add = (add*m)%MOD;
        mult=(mult*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())return -1;
        return (seq[idx]*mult+add)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */