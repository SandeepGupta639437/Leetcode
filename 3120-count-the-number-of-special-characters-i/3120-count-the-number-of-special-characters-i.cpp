class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        set<char>s;
        int n = word.size();
        for(int i=0;i<n;i++){
            s.insert(word[i]);
        }
        for(auto i : s){
          mp[i] = 1;
        }
        int ans = 0;

        for(auto i : s){
          if(mp[i+32]==1)ans++;
        }

        return ans;

    }
};