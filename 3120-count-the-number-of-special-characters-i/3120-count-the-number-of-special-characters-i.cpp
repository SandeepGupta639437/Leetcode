class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        int n = word.size();
        for(int i=0;i<n;i++){
          mp[word[i]] = 1;
        }
        int ans = 0;

        for(int i=0;i<n;i++){
          if(mp[word[i]+32]==1){
            ans++;
            mp[word[i]] = 0;
            mp[word[i]+32] = 0;
          }
        }

        return ans;

    }
};