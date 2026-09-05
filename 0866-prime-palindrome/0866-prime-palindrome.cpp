class Solution {
public:
    bool isPalin(int n){
        string s = to_string(n);
        int l = 0, r = s.length()-1;
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }

    bool isPrime(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        int no = (n==1)?2:n;

        while(true){
            if((no>1e3 && no<1e4) || (no>1e5 && no<1e6) || (no>1e7 && no<1e8)){
                no = pow(10,ceil(log10(no)));
                continue;
            }

            if(isPalin(no) && isPrime(no)){
                return no;
            }
            no++;
        }
        return no;
    }
};