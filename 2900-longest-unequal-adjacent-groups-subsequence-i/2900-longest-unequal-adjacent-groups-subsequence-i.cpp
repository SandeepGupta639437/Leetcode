class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans1,ans2;
        int flag = 0;

        int n = words.size();
        for(int i=0;i<n;i++){
            if(flag == 0 && groups[i]==0){
                ans1.push_back(words[i]);
                flag = !flag;
            }
            if(flag && groups[i] == 1) {
                ans1.push_back(words[i]);
                flag = !flag;
            }
        }
        flag = 0;
        for(int i=0;i<n;i++){
            if(flag == 1 && groups[i]==0){
                ans2.push_back(words[i]);
                flag = !flag;
            }
            if(flag == 0 && groups[i] == 1) {
                ans2.push_back(words[i]);
                flag = !flag;
            }
        }
        if(ans1.size()>ans2.size())return ans1;
        return ans2;
    }
};