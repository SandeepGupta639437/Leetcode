class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(word[i]>95)mp[word[i]]=max(mp[word[i]],i+1);
            else{
                if(mp[word[i]]==0)mp[word[i]] = i+1;
            }
        }
        int ans = 0;

        for(int i=0;i<n;i++){
          if(word[i]<93){
            if(mp[word[i]+32]<mp[word[i]] && mp[word[i]+32]>0){
                ans++;
                mp[word[i]+32] = 0;
            }
          }
        }

        return ans;

    }
};