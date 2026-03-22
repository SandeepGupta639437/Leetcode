class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n =mat.size();
        int flag=0;
        int cnt=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
              if(mat[i][j]!=target[i][j]){
                flag=1;
                cnt++;
                break;
              }
           }
           if(flag)break;
        }
        flag =0;
        int c =0,r=0;
        for(int j=0;j<n;j++){
           c=0;
           for(int i=n-1;i>=0;i--){
              if(mat[i][j]!=target[r][c]){
                flag=1;
                cnt++;
                break;
              }
              c++;
           }
           r++;
           if(flag)break;
        }

        flag =0;
        c =0,r=0;
        for(int i=n-1;i>=0;i--){
            c=0;
           for(int j=n-1;j>=0;j--){
              if(mat[i][j]!=target[r][c]){
                flag=1;
                cnt++;
                break;
              }
              c++;
           }
           r++;
           if(flag)break;
        }

        flag =0;
        c =0,r=0;
        for(int j=n-1;j>=0;j--){
            c=0;
           for(int i=0;i<n;i++){
              if(mat[i][j]!=target[r][c]){
                flag=1;
                cnt++;
                break;
              }
              c++;
           }
           r++;
           if(flag)break;
        }
        if(cnt==4)return false;
        return true;
    }
};