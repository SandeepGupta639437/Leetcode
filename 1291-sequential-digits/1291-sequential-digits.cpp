class Solution {
public:
    int digCnt(int n){int cnt = 0;while(n){n/=10;cnt++;}return cnt;}
    
    vector<int> sequentialDigits(int low, int high){
        string s = "123456789";
        int startDigCnt = digCnt(low);
        int lastDigCnt = digCnt(high);
        vector<int>ans;

        while(startDigCnt <= lastDigCnt){
            int k = startDigCnt;
            for(int i=0;i<10-k;i++){
                string num = "";
                for(int j=i;j<i+k;j++){
                    num += s[j];
                }
                int N = stoi(num) ;
                if(N>=low && N<=high){
                    ans.push_back(N);
                }
            }
            startDigCnt++;
        }
        return ans;
    }
};