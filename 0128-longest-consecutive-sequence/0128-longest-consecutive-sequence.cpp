class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)mp[it] = 1;
        int first = mp.begin()->first;
        int cnt = 1;
        int ans = 0;
        for(auto it:mp){
            if(it.first==first+1){
                cnt++;
                ans = max(ans,cnt);
            }else{
                cnt = 1;
            }
            first = it.first;
        }
        ans = max(ans,cnt);
        return (nums.size()==0)?0:ans;

    }
};