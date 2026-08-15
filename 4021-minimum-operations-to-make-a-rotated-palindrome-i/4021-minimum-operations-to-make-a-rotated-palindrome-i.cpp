class Solution {
public:
    int solve(string &s){
        int i = 0, j = s.size()-1;
        int cnt = 0;
        while(i<j){
            int x = (s[j]-s[i]+26)%26;
            int y = (s[i]-s[j]+26)%26;
            cnt += min(x,y);
            i++;
            j--;
        }
        return cnt;
    }
    int minOperations(string s) {
        int n = s.length();
        s += s;
        vector<string>v(n);
        for(int i=0;i<n;i++){
            for(int j=i;j<i+n;j++){
                v[i].push_back(s[j]);
            }
        }

        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            string temp = v[i];
            int op = i + solve(temp);
            ans = min(ans,op);
        }
        return ans;
    }
};