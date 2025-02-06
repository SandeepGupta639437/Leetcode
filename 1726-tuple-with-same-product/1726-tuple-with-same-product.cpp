class Solution {
    int fact(int x){
       int sum=1;
        for(int i=1;i<=x;i++){
           sum*=i;
        }
        return sum;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int>freq;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
               freq[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto&it:freq){
            ans+=(fact(it.second))/((fact(it.second-2))*fact(2));
        }
        return ans*8;

    }
};