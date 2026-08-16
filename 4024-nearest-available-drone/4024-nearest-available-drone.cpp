class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int i = 0;
        int minDist = INT_MAX;
        int ans = -1;
        for(auto &v : drones){
            int X = v[0];
            int Y = v[1];
            int range = v[2];
            int dist = (abs(x-X)+abs(y-Y));
            if(dist<=range){
                if(dist<minDist){
                    minDist = dist;
                    ans = i;
                }
            }
            i++;
        }
        return ans;
    }
};