class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;

        int flipCountFromPastFori = 0;

        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]==5){
                flipCountFromPastFori--;
            }

            if(flipCountFromPastFori % 2 == nums[i]){ // flip at index i  // odd and 1 require flip ...similarly even and 0 required flips
                if(i+k>n)return -1;

                flipCountFromPastFori++;
                flips++;
                nums[i] = 5;

            }

        }

        return flips;
    }
};