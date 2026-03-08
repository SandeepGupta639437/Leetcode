class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>integers;
        for(int i=0;i<nums.size();i++){
            integers.insert(stoi(nums[i],0,2));
        }
        for(int i=0;i<=nums.size();i++){
            if(integers.find(i)==integers.end()){
                string ans=bitset<16>(i).to_string();
                return ans.substr(16-nums.size());
            }
        }
    return " ";
    }
};