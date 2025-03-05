class Solution {
public:
    long long coloredCells(int n) {
        int i=1;
        int j=1;
        if(n==1)return 1;
       while(true){
          i++;
          if(i==n)return pow(j,2)+4;
          j+=2;
       }
    }
};