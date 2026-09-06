class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int groups = 1;
        int l = n-1;
        int r = n-1;
        for(int i=n-2;i>=0;i--){
            if(position[l]-position[i] <= distance || speed[i]>speed[r]){
                l=i;
            }
            else{
                groups++;
                l = i;
                r=i;
            }
        }
        return groups;
    }
};