class Solution {
public:
    int mirrorDistance(int n) {
        int m=n;
        int newn=0;
        while(m){
            newn=newn*10+m%10;
            m/=10;
        }
        return abs(newn-n);
        
    }
};