class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;

        int flipCountFromPastFori = 0;

        vector<bool> isFlipped(n,false);

        for(int i=0;i<n;i++){
            if(i>=k && isFlipped[i-k]==true){
                flipCountFromPastFori--;
            }

            if(flipCountFromPastFori % 2 == nums[i]){ // flip at index i  // odd and 1 require flip ...similarly even and 0 required flips
                if(i+k>n)return -1;

                flipCountFromPastFori++;
                flips++;
                isFlipped[i] = true;

            }

        }

        return flips;
    }
};