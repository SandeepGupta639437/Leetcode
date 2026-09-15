class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<long long,vector<int>>mpp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto it:mpp){
            if(it.second.size()<3)continue;
            else{
                int flag = false;
                int diff = it.second[1]-it.second[0];
                for(int i=1;i<it.second.size();i++){
                    if(it.second[i]-it.second[i-1] == diff)continue;
                    else flag=true;
                }
                if(!flag)ans++;
            }
        }
        return ans;
    }
};