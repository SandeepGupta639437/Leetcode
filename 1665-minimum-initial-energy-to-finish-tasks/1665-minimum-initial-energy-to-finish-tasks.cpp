class Solution {
public:
    bool possible(int mid,vector<vector<int>>& tasks){
        int energy = mid;
        for(auto it : tasks){
            if(it[1]>energy)return false;
            else energy-=it[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int start = 0, last = 1e9;
        int ans = 1e9;
       auto lambda = [](auto &task1, auto& task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);

        while(start<=last){
            int mid = start - (start-last)/2;
            if(possible(mid,tasks)){
                ans = min(ans,mid);
                last = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};