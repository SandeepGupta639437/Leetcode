class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto it:nums)st.insert(it);
        int first = *st.begin();
        int cnt = 1;
        int ans = 0;
        for(auto it:st){
            if(it==first+1){
                cnt++;
                ans = max(ans,cnt);
            }else{
                cnt = 1;
            }
            first = it;
        }
        ans = max(ans,cnt);
        return (nums.size()==0)?0:ans;

    }
};