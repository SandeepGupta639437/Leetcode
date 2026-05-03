class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>v(n+m);
        int j = 0;
        for(int i=0;i<n;i++){
            v[j] = nums1[i];
            j++;
        }
        for(int i=0;i<m;i++){
            v[j] = nums2[i];
            j++;
        }

        sort(v.begin(),v.end());
        if((n+m)%2){
            int x = (n+m)/2;
            return v[x];

        }else{
            int x = (n+m)/2 - 1;
            int y = (n+m)/2;

            double  temp = (double(v[x])+double(v[y]))/2.00;
            return temp;

        }

        return 0;
    }
};
