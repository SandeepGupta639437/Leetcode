class Solution {
public:
    int n ;
    void solve(string curr,vector<string>&v){
        if(curr.length()==n){
            v.push_back(curr);
            return ;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back()==ch)continue;

            //Do
            curr+=ch;
            //Explore
            solve(curr,v);
            //Undo
            curr.pop_back();

        }
        return ;
    }
    string getHappyString(int n_, int k) {
        n=n_;
        vector<string>v;
        string curr="";
        solve(curr,v);
        if(k > v.size()) return "";
        return v[k-1];
    }
};