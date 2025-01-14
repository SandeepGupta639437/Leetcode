class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int count=0;
        vector<int>c(n,0);
        for(int i=0;i<n;i++){
            bool found=false;
            for(int j=0;j<n;j++){
                if(A[i]==B[j]){
                    found=true;
                }
                if(found && j>=i){
                    c[j]++;
                }
            }
        }
        return c;
    }
};