class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        for(char ch : b){
            if(a.find(ch) == string::npos)
                return -1;
        }

        string original = a;
        int ans = 1;

        while(a.size() < b.size()){
            a += original;
            ans++;
        }

        if(a.find(b) != string::npos)
            return ans;

        a += original;
        ans = ans+1;

        if(a.find(b) != string::npos)
            return ans;

        return -1;
    }
};