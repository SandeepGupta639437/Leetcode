class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=1;i<=100;i++){
            bool flag = false;
            int prev = -1;
            bool notPossible = false;

            for(int j=0;j<n;j++){

                if(nums[j]==i && !flag){
                    prev = j;
                    flag = true;
                    continue;
                }

                if(nums[j]==i){
                    if(j-prev !=1){
                        notPossible  = true;
                        break;
                    }
                    prev = j;
                }

            }

            if(prev!=-1 && !notPossible){
                ans++;
            }
        }

        return ans;
    }
};