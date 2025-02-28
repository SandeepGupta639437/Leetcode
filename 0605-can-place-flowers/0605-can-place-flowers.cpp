class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        for(int i=0;i<flowerbed.size()-1;i++){
            if(flowerbed[i+1]==0 && flowerbed[i+2]==0){
               count++;
               i++;
            }
        }
        if(count>=n)return true;
        else return false;
    }
};