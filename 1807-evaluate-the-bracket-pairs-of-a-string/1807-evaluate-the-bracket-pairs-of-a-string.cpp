class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto &v:knowledge){
            mpp[v[0]] = v[1];
        }

        string ans = "";
        string temp ="";

        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                while(s[i]!=')'){
                    temp += s[i];
                    i++;
                }
                if(mpp.find(temp)==mpp.end())ans+='?';
                else ans += mpp[temp];
                temp = "";
            }else{
                ans+=s[i];
            }
        }

        return ans;
    }
};