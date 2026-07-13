class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0 , n = arr.size();
        int num = 1;
        while(i<n && k>0){
            if(arr[i]==num){
                i++;
            }else{
                k--;
            }
            num++;
        }
        return num+k-1;
    }
};