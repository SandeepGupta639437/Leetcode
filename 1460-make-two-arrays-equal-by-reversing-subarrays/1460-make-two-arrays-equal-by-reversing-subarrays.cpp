class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
               if(arr[i]==target[j]){flag=1;
               target[j]=INT_MAX;
               break;
               }
            }
            if(flag==0)return false;
        }
        return true;
    }
};