class Solution {
public:
    bool rot(vector<int>&A,vector<int>&B){
        int k = A.size();
        for(int i=0;i<k;i++){
            bool ok = true;
            for(int j=0;j<k;j++){
                if(A[j]!=B[(i+j)%k]){
                    ok = false;
                    break;
                }
            }
            if(ok)return true;
        }
        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        auto temp = nums;
        vector<int>str = nums;
        sort(begin(str),end(str));
        int ans =0;
        for(int k=1;k<=n;k++){
            if(n%k!=0)continue;
            bool flag = true;
            for(int i=0;i<n;i+=k){
                vector<int>A(nums.begin()+i,nums.begin()+i+k); 
                vector<int>B(str.begin()+i , str.begin()+i+k);
                if(!rot(A,B)){
                    flag = false;
                    break;
                }
            }
            if(flag)ans+=k;
        }
        return ans;
    }
};