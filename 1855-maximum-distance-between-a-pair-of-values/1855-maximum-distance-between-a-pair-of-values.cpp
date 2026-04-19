class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans =0;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;i++){
            int s = i,e=m-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(nums1[i] <= nums2[mid]){
                    s = mid+1;
                    ans =max(ans,mid-i);
                }else{
                    e = mid - 1;
                }
            }
        }
        return ans;
    }
};