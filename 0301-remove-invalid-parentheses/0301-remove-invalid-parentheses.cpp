class Solution {
public:
    set<string>ans;
    int n;
    void solve(int i,string &s,string &temp,int cnt){
        if(cnt<0)return;

        if(i == n){
            if(cnt == 0)
                ans.insert(temp);
            return;
        }

        if(s[i]=='('){
            string temp2 = temp;
            temp.push_back('(');
            solve(i+1,s,temp,cnt+1);
            temp = temp2;
            solve(i + 1, s, temp, cnt);
        }else if(s[i]==')'){
            string temp2 = temp;
            temp.push_back(')');
            solve(i+1,s,temp,cnt-1);
            temp = temp2;
            solve(i + 1, s, temp, cnt);
        }else{
            temp.push_back(s[i]);
            solve(i+1,s,temp,cnt);
        }

        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp = "";
        n = s.size();
        solve(0,s,temp,0);
        vector<string>ans2;

        int maxi = 0;

        for(auto &it : ans)
            maxi = max(maxi, (int)it.size());

        for(auto &it : ans) {
            if(it.size() == maxi)
                ans2.push_back(it);
        }

        return ans2;
    }
};