class Solution {
public:
    int n,m;

    bool solve(int i,int j,string &s,string &p){

        if(i==n && j==m)
            return true;

        if(j==m) return false;

        bool firstMatch = (i<n &&  (s[i]==p[j] || p[j]=='.'));

        if(j+1<m && p[j+1]=='*'){
            return solve(i,j+2,s,p) || (firstMatch && solve(i+1,j,s,p));
        }

        return firstMatch && solve(i+1,j+1,s,p);
    }

    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();

        return solve(0,0,s,p);
    }
};