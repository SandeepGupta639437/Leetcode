class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>temp;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
        }
        for(auto &it:temp){
            if(it.second%2)return false;
        }
        return true;
    }
};