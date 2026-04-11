class Solution {
public:
    const int MAXN = 200005;
    
    int minOperations(vector<int>& nums) {
        vector<int>isPrime(MAXN,1);
        isPrime[0]=isPrime[1]=0;
        for(int i=2;i*i<MAXN;i++){
            if(isPrime[i]){
                for(int j=i*i;j<MAXN;j+=i){
                    isPrime[j]=0;
                }
            }
        }

        // vector<int>nextPrime(MAXN);
        // int last = -1;

        // for(int i=MAXN-1;i>=0;i--){
        //     if(isPrime[i])last=i;
        //     nextPrime[i]=last;
        // }

        int n = nums.size();

        int ans =0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(!isPrime[nums[i]]){
                    int y = nums[i];
                    while(!isPrime[y])y++;
                    ans += (y - nums[i]);
                }
            }else{
                if(isPrime[nums[i]]){
                    if(nums[i]==2)ans+=2;
                else ans+=1;
                } 
            }
        }
        return ans;
    }
};