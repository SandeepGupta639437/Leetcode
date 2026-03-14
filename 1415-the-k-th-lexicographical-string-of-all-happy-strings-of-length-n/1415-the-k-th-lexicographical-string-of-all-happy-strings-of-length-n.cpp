class Solution {
public:
    int n ;
    void solve(vector<string>&v,string s,char curr,int cnt){
        if(cnt==n){
            v.push_back(s);
            return ;
        }
        if(curr=='a'){
            solve(v,s+'b','b',cnt+1);
            solve(v,s+'c','c',cnt+1);
        }
        if(curr=='b'){
            solve(v,s+'a','a',cnt+1);
            solve(v,s+'c','c',cnt+1);
        }
        if(curr=='c'){
            solve(v,s+'a','a',cnt+1);
            solve(v,s+'b','b',cnt+1);
        }
        return ;
    }
    string getHappyString(int n_, int k) {
        n=n_;
        vector<string>v;
        string s;
        char curr = 'a';
        solve(v,s+'a',curr,1);
        curr = 'b';
        solve(v,s+'b',curr,1);
        curr = 'c';
        solve(v,s+'c',curr,1);
        sort(v.begin(),v.end());
        if(k > v.size()) return "";
        return v[k-1];
    }
};