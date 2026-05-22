class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        vector<string> res;
        string p="";
        for(int i=0;i < 10 && i<s.size();i++)
        {
            p+=s[i];
        } // make first window of size 10
        m[p]=1;
        for(int i=10;i<s.size();i++)
        {
            p=p.substr(1)+s[i]; // sliding the window
            if(m.count(p) != 0 && m[p] == 1)
            {
                res.push_back(p);
            }
            m[p]+=1;
        }
        return res;
    }
};