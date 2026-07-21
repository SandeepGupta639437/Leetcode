class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int activeCount = count(begin(s),end(s),'1');

        vector<int>inactiveBlocks;

        int i = 0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i] == '0')i++;

                inactiveBlocks.push_back(i-start);
            }else i++;
        }

        int maxPair = 0;
        int m = inactiveBlocks.size();
        for(int i=0;i<m-1;i++){
            maxPair = max(maxPair, inactiveBlocks[i]+inactiveBlocks[i+1]);
        }
        return maxPair + activeCount;
        
    }
};