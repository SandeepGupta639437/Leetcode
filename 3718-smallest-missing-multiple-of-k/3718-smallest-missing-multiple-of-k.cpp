class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int &it:nums)mp[it]++;
        int i;
        for(i=k;i<=100;i+=k){
            if(mp[i]==0)return i;
        }
        return i;
    }
};