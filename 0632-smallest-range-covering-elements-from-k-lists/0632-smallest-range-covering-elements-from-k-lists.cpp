class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int>resultRange = {-100000,100000};

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int maxEl = INT_MIN;

        for(int i=0;i<k;i++){
           pq.push({nums[i][0],i,0});
           maxEl = max(maxEl,nums[i][0]);
        }

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int minElIdx = curr[2];

            if(maxEl - minEl < resultRange[1]-resultRange[0]){
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            if(minElIdx+1 >= nums[listIdx].size())break;

            int nextIdx = minElIdx+1;

            pq.push({nums[listIdx][nextIdx],listIdx,nextIdx});

            maxEl = max(maxEl,nums[listIdx][nextIdx]);

        }

        return resultRange;
    }
};