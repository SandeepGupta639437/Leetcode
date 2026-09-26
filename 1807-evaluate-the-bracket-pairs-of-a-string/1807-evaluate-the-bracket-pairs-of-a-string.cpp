class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mpp;
        for(auto &v:knowledge){
            mpp[v[0]] = v[1];
        }

        string ans = "";

        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                string temp = "";
                while(s[i]!=')'){
                    temp += s[i];
                    i++;
                }
                if(mpp.find(temp)==mpp.end())ans+='?';
                else ans += mpp[temp];
            }else{
                ans+=s[i];
            }
        }

        return ans;
    }
};