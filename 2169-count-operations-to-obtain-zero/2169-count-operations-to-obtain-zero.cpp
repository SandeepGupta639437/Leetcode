class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt=0;
        if(num1==0 || num2==0){
            return 0;
        }
        while(true){
            if(num1==num2)return cnt+1;
            if(num2>num1){
                num2-=num1;
                cnt++;
            }
            else{
                num1-=num2;
                cnt++;
            }

            if(num1 ==0 || num2==0)return cnt;
        }
    }
};