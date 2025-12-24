class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        int n=apple.size();
        int m=capacity.size();
        for(int i=0;i<n;i++){
         total+=apple[i];
        }
        sort(capacity.begin(),capacity.end(),greater<int>());
        int capa=0;
        for(int i=0;i<m;i++){
           capa+=capacity[i];
           if(capa>=total)return i+1;
        }
        return 0;
    }
};