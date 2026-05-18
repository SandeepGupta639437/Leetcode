class Solution {
public:
    int maxDistinct(string s) {
        int n = s.size();
        set<char>st;
        for(auto i:s){
            st.insert(i);
        }
        return st.size();
    }
};