class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> diff(1001, 0);  // because max location = 1000
        
        for (auto &v : trips) {
            int passengers = v[0];
            int from = v[1];
            int to = v[2];
            
            diff[from] += passengers;   // passengers enter
            diff[to] -= passengers;     // passengers leave
        }
        
        int currPass = 0;
        
        for (int i = 0; i <= 1000; i++) {
            currPass += diff[i];
            if (currPass > capacity)
                return false;
        }
        
        return true;
    }
};
