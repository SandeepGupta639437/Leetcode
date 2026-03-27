class Solution {
public:
    void reverse(vector<vector<int>>& a, int l, int r,int i){
        while(l < r){
            swap(a[i][l], a[i][r]);
            l++; r--;
        }
    }
    void rotateRight(vector<vector<int>>& a, int k,int i){
        int n = a[i].size();
        k = k % n;

        reverse(a, 0, n-1,i);   // step 1
        reverse(a, 0, k-1,i);   // step 2
        reverse(a, k, n-1,i);   // step 3
    }
    void rotateLeft(vector<vector<int>>& a, int k,int i){
        int n = a[i].size();
        k = k % n;

        reverse(a, 0, k-1,i);
        reverse(a, k, n-1,i);
        reverse(a, 0, n-1,i);
    }


    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>temp(begin(mat),end(mat));
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0;i<m;i++){
            if(i%2){
                rotateRight(mat,k,i);
            }else{
                rotateLeft(mat,k,i);
            }
        }
        if(mat==temp)return true;
        return false;
    }
};