class Solution {
public:
    int n;
    vector<int>evenPref;
    vector<int>oddPref;
    double a,b;
    double rat2;

    bool valid(int l,int r,vector<int>& nums){
        double x = evenPref[r] - ((l==0)?0:evenPref[l-1]);
        double y = oddPref[r] - ((l==0)?0:oddPref[l-1]);
        if (y == 0) return false;
        return (x*b<=y*a);
    }


    int countRatioSubarrays(vector<int>& nums, int A, int B) {
        n = nums.size();
        a=A;b=B;
        rat2 = a/b;
        evenPref.resize(n);
        oddPref.resize(n);
        if(nums[0]%2){
            evenPref[0] =0;
            oddPref[0] = 1;
        }else{
            evenPref[0] = 1;
            oddPref[0] = 0;
        }

        for(int i=1;i<n;i++){
            evenPref[i] +=evenPref[i-1] + ((nums[i]%2)?0:1);
            oddPref[i] += oddPref[i-1] + ((nums[i]%2)?1:0);
        }

        int ans  =  0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (valid(l, r, nums))
                    ans++;
            }
        }
        return ans;
    }
};