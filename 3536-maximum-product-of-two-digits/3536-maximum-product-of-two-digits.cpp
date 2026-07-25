class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        sort(begin(v),end(v));
        int m = v.size();
        return v[m-1]*v[m-2];
    }
};