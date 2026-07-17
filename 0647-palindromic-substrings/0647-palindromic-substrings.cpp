class Solution {
public:
    int countSubstrings(string s) {
        string z;
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            z="";
            for(int j=i;j<n;j++){
                z = s.substr(i, j - i + 1);
                string temp = z;
                reverse(z.begin(),z.end());
                if(temp==z){
                    ans++;
                }
            }
        }
        return ans;
    }
};