class Solution {
public:
    int dig(string& s){
        int l = s.length();
        int n = 0;
        for(int i=0;i<l;i++){
            int d = s[i]-'0';
            n = 1LL*n*10 + d;
        }
        return n;
    }
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int startDigCnt = 0;
        int lastDigCnt = 0;
        int low_ = low;
        int high_ = high;
        while(low_){
            low_/=10;
            startDigCnt++;
        }
        while(high_){
            high_/=10;
            lastDigCnt++;
        }
        vector<int>ans;

        while(startDigCnt <= lastDigCnt){
            int k = startDigCnt;
            for(int i=0;i<10-k;i++){
                string num = "";
                for(int j=i;j<i+k;j++){
                    num += s[j];
                }
                int N = dig(num) ;

                if(N>=low && N<=high){
                    ans.push_back(N);
                }
            }
            startDigCnt++;
        }
        return ans;
    }
};