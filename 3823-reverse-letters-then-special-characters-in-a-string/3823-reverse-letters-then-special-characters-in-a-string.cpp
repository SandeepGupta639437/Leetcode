class Solution {
public:
    string reverseByType(string s) {
        string alpha="";
        string spec="";
        for(auto i:s){
            if(!isalpha(i)){
                spec+=i;
            }else alpha+=i;
        }
        reverse(spec.begin(), spec.end());
        reverse(alpha.begin(), alpha.end());
        int l=0,m=0;
        for(int i=0;i<s.size();i++){
            if(!isalpha(s[i])){
                s[i]=spec[l];
                l++;
            }
            else {
                s[i]=alpha[m];
                m++;
            }
        }
        return s;
        
    }
};