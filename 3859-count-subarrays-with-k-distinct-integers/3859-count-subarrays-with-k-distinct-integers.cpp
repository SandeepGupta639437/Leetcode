class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        
        int i = 0;        // like leftd
        int leftv = 0;    // second pointer
        
        unordered_map<int,int> mpp;     // for distinct count
        unordered_map<int,int> mppv;    // for >= m condition
        
        long long ans = 0;
        int valid = 0;   // number of elements having freq >= m
        
        for(int j = 0; j < n; j++){

            // expand distinct window
            mpp[nums[j]]++;
            while(mpp.size() > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            // expand valid window
            mppv[nums[j]]++;
            if(mppv[nums[j]] == m) valid++;

            while(valid >= k){
                if(mppv[nums[leftv]] == m) valid--;
                mppv[nums[leftv]]--;
                leftv++;
            }

            // count valid subarrays
            if(leftv > i){
                ans += (leftv - i);
            }
        }
        return ans;
    }
};