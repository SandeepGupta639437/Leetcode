class Solution {
public:

    bool dfs(vector<int>& arr, int i){

        int n = arr.size();

        if(i < 0 || i >= n || arr[i]<0)
            return false;

        if(arr[i] == 0)
            return true;

        arr[i] *= -1;

        return dfs(arr, i + arr[i]) || dfs(arr, i - arr[i]);
    }

    bool canReach(vector<int>& arr, int start) {

        return dfs(arr, start);
    }
};