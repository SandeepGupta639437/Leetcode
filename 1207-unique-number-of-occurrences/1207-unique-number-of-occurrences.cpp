class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mpp;
        for(int it:arr){
            mpp[it]++;
        }
        set<int>st;
        for(auto it:mpp){
            st.insert(it.second);
        }
        if(mpp.size()==st.size())return true;
        return false;
    }
};