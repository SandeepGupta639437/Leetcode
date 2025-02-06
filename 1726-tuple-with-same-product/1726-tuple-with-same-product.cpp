class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int>freq;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
               freq[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto&it:freq){
            ans+=((it.second *(it.second-1))/2);
        }
        return ans*8;

    }
};