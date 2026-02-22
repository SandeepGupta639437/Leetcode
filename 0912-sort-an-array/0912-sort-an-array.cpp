class Solution {
public:
    int count[100001];  

    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0; i < 100001; ++i) count[i] = 0;

        for (int x : nums) {
            count[x]++;
        }
        
        int index=0;
        for (int i=0;i<100001;++i) {
            int c=count[i];
            if (c>=0){
                int val = i;
                while (c--) {
                    nums[index++] = val;
                }
            }
        }
        return nums;
    }
};