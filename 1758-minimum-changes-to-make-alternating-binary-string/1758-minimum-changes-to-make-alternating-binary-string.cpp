class Solution {
public:
    int minOperations(string s) {
        int e0=0,e1=0,o0=0,o1=0;
        int n=s.size();
        for(int i=0;i<n;i++){
           if(s[i]=='0' && i%2==0)e0++;
           if(s[i]=='0' && i%2)o0++;
           if(s[i]=='1' && i%2==0)e1++;
           if(s[i]=='1' && i%2)o1++;
        }
        return min(o1+e0,o0+e1);
        
    }
};