class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>v1;
        vector<int>v2;
        int x = nums[0];
        int y = nums[1];
        v1.push_back(x);
        v2.push_back(y);
        int n = nums.size();
        for(int i=2;i<n;i++){
            if(x>y){
                v1.push_back(nums[i]);
                x = nums[i];
            }else{
                v2.push_back(nums[i]);
                y = nums[i];
            }
        }

        vector<int>result;

        for(int i=0;i<v1.size();i++){
            result.push_back(v1[i]);
        }
        for(int i=0;i<v2.size();i++){
            result.push_back(v2[i]);
        }

        return result;
    
    }
};