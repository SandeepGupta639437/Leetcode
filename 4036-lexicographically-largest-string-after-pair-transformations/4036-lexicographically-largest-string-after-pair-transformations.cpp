class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n  = nums.size();
        vector<string>ans;

        for(int i=0;i<n;i++){
            int total = nums[i];
            string str = "";
            while (total >= (1LL << 25)) {
                str += 'z';
                total -= (1LL << 25);
            }
            for(char ch = 'z';ch>='a' ; ch--){
                if(total >= pow(2,ch-'a')){
                    str += ch;
                    total -= pow(2,ch-'a');
                }
            }

            ans.push_back(str);
        }

        return ans;
    }
};