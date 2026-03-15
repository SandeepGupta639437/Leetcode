class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int>mpp;
        for(auto i:nums){
            if(i%2==0)mpp[i]++;
        }
        for(auto i:nums){
            if(mpp[i]==1)return i;
        }
        return -1;
    }
};