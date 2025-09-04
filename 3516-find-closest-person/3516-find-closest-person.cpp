class Solution {
public:
    int findClosest(int x, int y, int z) {
        int firstDif=abs(x-z);
        int secondDif=abs(y-z);
        if(firstDif<secondDif){
            return 1;
        }
        else if(firstDif>secondDif){
            return 2;
        }
        else return 0;
        return 0;
    }
};