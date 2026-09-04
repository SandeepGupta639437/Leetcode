class Solution {
public:
    string check(int x,int n,int k){
        long long result = x;
        int to_add;

        if(n % 2) to_add = result / 10;
        else to_add = result;

        while(to_add){
            result = result*10 + (to_add%10);
            to_add/=10;
        }

        string s = to_string(result);
        
        if(result%k==0)return s;
        return "-1";
    }

    long long fact(int n) {
        long long ans = 1;

        for (int i = 2; i <= n; i++)
            ans *= i;

        return ans;
    }

    long long countPermutations(string &s) {

        int freq[10] = {};

        for(char ch : s)
            freq[ch - '0']++;

        // Total permutations
        long long total = fact(s.length());

        for(int i = 0; i < 10; i++) total /= fact(freq[i]);

         // No leading zero problem
        if(freq[0] == 0) return total;

        // Count permutations starting with zero
        long long invalid = fact(s.length() - 1);

        invalid /= fact(freq[0] - 1);

        for(int i = 1; i < 10; i++)
            invalid /= fact(freq[i]);

        return total - invalid;
    }

    long long countGoodIntegers(int n, int k) {
        int half = (n+1)/2;
        int start = 1; 
        for(int i=2;i<=half;i++){
            start*=10;
        }
        int end = start*10;
        int ans = 0;

        set<vector<int>> seen;

        for(int x = start;x<end;x++){

            string palin = check(x,n,k);

            if(palin=="-1")continue;

            vector<int> freq(10, 0);

            for(char ch : palin) freq[ch - '0']++;

            // Already counted this digit multiset
            if(seen.count(freq)) continue;

            seen.insert(freq);

            ans+=countPermutations(palin);
        }

        return ans;
    }
};