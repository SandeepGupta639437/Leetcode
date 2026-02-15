class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        vector<string>temp = words;
        unordered_map<string,int>cnt;

        for(auto &i : temp){
            if(i.size()<k)continue;  //not possible
            string pref = i.substr(0,k);
            cnt[pref]++;
        }
        int ans=0;
        for(auto &j :cnt){
            if(j.second>=2)ans++;
        }
        return ans;  
    }
};