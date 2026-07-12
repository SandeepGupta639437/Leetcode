class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp;
        temp = arr;
        sort(temp.begin(),temp.end());
        map<int,int>mpp;
        int n = arr.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(mpp[temp[i]]==0){
                 mpp[temp[i]] = j+1;
                 j++;
            }    
        }
        for(int i=0;i<n;i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};