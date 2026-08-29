class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n  = nums.size();
        vector<string>ans;

        for(int i=0;i<n;i++){
            int total = nums[i];
            string str = "";
            while (total >= pow(2,'z'-'a') ) {
                str += 'z';
                total -= pow(2,'z'-'a') ;
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