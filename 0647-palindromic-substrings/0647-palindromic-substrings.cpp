class Solution {
public:
    int count = 0;
    int n;
    void check(int i,int j, string& s){
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return;
    }
    int countSubstrings(string s) {
        n = s.length();
        for(int i=0;i<n;i++){
            check(i,i,s);
            check(i,i+1,s);
        }
        return count;
    }
};