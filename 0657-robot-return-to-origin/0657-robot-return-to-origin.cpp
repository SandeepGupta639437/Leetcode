class Solution {
public:
    bool judgeCircle(string moves) {
        int x1 =0,x2=0;

        for(auto i:moves){
            if(i=='U')x1++;
            if(i=='D')x1--;
            if(i=='L')x2++;
            if(i=='R')x2--;
        }
        if(x1==0 && x2==0)return true;
        return false;
        
    }
};