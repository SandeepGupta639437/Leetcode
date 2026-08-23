class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();


        int ans = 0;
        int ops = 0;

        for(int i=0;i<n;i++){
            if(target[i]>ops){
                ans += (target[i]-ops);
                ops = target[i];
            }else{
                ops = target[i];
            }
        }

        return ans;
    }
};