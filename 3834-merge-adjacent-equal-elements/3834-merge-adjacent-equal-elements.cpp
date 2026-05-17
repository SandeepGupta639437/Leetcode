class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(!st.empty() && st.top() == nums[i]){
                long long y = nums[i] + nums[i];
                st.pop();
                while(!st.empty() && st.top() == y){
                    y *=2;
                    st.pop();
                }
                st.push(y);
            }else{
                st.push(nums[i]);
            }
        }
        int n_ = st.size();
        vector<long long>ans(n_,0);

        for(int i=n_-1;i>=0;i--){
            ans[i] = (long long)st.top();
            st.pop();
        }
        return ans;
    }
};