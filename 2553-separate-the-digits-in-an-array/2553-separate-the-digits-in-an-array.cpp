class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums){
            int n = it;
            vector<int>temp;
            while(n>0){
                int d = n%10;
                n/=10;
                temp.push_back(d);
            }
            int m = temp.size();
            for(int i = m-1;i>=0;i--){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};