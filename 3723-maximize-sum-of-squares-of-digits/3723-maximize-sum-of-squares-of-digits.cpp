class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(num){
            if(sum==0){
                ans += "0";
            }else if(sum>9){
                ans += "9";
                sum-=9;
            }else{
                ans += to_string(sum);
                sum = 0;
            }
            num--;
        }


        if(sum)return "";
        return ans;
    }
};