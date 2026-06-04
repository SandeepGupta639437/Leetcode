class Solution {
public:
    int waiveness(int n){
        vector<int>a;
        while(n){
            a.push_back(n%10);
            n/=10;
        }
        int cnt = 0;
        int m = a.size();
        for(int i=1;i<m-1;i++){
            if(a[i-1]>a[i] && a[i+1]>a[i])cnt++;
            if(a[i-1]<a[i] && a[i+1]<a[i])cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++){
            ans+=waiveness(i);
        }
        return ans;
    }
};