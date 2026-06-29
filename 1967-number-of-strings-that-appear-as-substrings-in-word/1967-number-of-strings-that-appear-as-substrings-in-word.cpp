class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans =0;
        
        for(auto sub : patterns){
            if (word.find(sub) != string::npos) {
                ans++;
            }
        }
        return ans;
    }
};