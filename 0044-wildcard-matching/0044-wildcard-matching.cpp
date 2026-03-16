class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s, string &p, int i, int j){
        if(i==s.size() && j==p.size())return true;
        if(j==p.size()) return false;
        if(i==s.size()){
            if(p[j]=='*')return solve(s,p,i,j+1);
            return false;
        }
        if(p[j]=='?' || (s[i]==p[j]))return solve(s,p,i+1,j+1);
        else if(p[j]=='*')return (solve(s,p,i+1,j)||solve(s,p,i,j+1));
        else return false;

    }

    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
    }
};