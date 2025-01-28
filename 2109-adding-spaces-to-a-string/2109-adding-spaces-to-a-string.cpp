class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int i=0;
        int j=0;
        for(auto it : s){
            if( j<spaces.size() && i==spaces[j] ){
               ans+=" ";
               j++;
            }
            ans+=it;
            i++;
        }
        return ans;
    }
};