class Solution {
public:
    int count[100001];  

    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0; i < 100001; ++i) count[i] = 0;
        int min_v = 50000, max_v = -50000;

        for (int x : nums) {
            count[x + 50000]++;
            if (x < min_v) min_v = x;
            if (x > max_v) max_v = x;
        }
        
        int index=0;
        for (int i=min_v+50000;i<=max_v+50000;++i) {
            int c=count[i];
            if (c>0){
                int val = i - 50000;
                while (c--) {
                    nums[index++] = val;
                }
            }
        }
        return nums;
    }
};