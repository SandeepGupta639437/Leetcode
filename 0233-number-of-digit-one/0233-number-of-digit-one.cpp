class Solution {
public:
    int cntOne(int n ){
        int cnt =0;
        while(n){
            if(n%10==1)cnt++;
            n/=10;
        }
        return cnt;
    }
    int countDigitOne(int n) {
        int ans =0,prev=0;
        map<int,int>mpp;
        int j=99;
        while( j<=n){
            int ones = cntOne(j)*100 + 20;
            mpp[j]=ones+prev;
            // cout<<mpp[j]<<" "<<j<<endl;
            prev=mpp[j];
            j+=100;
        }
        int i=n;
        // cout<<mpp[j-100]<<" "<<j-100<<" "<<n<<" "<<endl;
        for(i=n;(i+1)%100!=0;i--){
            ans+=cntOne(i);
        }
        // int temp=n%100;
        // ans+=cntOne(n-temp);
        // if(n%100==0 && n>99)ans++;
        return mpp[j-100]+ans;
    }
};