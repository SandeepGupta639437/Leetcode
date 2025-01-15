class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>new1(heights.begin(),heights.end());
        sort(new1.begin(),new1.end());
        int count=0;
        for(int i=0;i<new1.size();i++){
            if(new1[i]==heights[i])continue;
            else count++;
        }
        return count;
    }
};