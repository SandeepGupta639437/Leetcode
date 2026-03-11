class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int m = 0;
        int temp = n;
        while(temp){
            temp >>= 1;
            m++;
        }
        int mask = (1 << m) - 1;
        return n ^ mask;
    }
};