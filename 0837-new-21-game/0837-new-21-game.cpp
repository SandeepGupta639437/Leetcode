class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // double p[n+1];
        vector<double>p(n+1,0);
        p[0] = 1;
        double currProbSum = (k==0) ? 0 : 1;

        for(int i=1;i<=n;i++){
            p[i] = currProbSum / maxPts;

            if(i<k){
                currProbSum += p[i];
            }

            if(i-maxPts >= 0 && i-maxPts < k){
                currProbSum -= p[i-maxPts]; 
            }
        }

        // double ans = 0.0;

        // for(int i=k;i<=n;i++){
        //     ans += (p[i]);
        // }

        // return ans;

        return accumulate(p.begin()+k,p.end(),0.0);
    }
};