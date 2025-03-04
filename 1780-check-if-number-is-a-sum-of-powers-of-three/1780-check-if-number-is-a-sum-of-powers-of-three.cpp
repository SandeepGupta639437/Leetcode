class Solution {
public:
    bool checkPowersOfThree(int n) {
        //binary number ki trh isko convert krte hai aur usme koi number 2 aa jayega 
        //to condition follow nhi krega   same power ho jayega.
        while(n){
            if(n%3==2)return false;
            n/=3;
        }
        return true;
    }
};