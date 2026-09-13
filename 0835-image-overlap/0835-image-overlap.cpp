class Solution {
public:
    int n;
    int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int rowOffset,int colOffset){
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int I = i+rowOffset;
                int J = j+colOffset;
                if(I>=0 && I<n && J>=0 && J<n){
                    if(img2[i][j] == 1 && img1[I][J]==1)count++; 
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();

        int maxOverlap = 0;

        for(int rowOffset = -n+1;rowOffset < n; rowOffset++){
            for(int colOffset = -n+1;colOffset < n ; colOffset++){
                int count = countOverlaps(img1,img2,rowOffset,colOffset);

                maxOverlap = max(maxOverlap,count);
            }
        }

        return maxOverlap;
    }
};