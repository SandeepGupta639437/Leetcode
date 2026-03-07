class Solution {
public:
    int minFlips(string s) {
        int n= s.size();
        s=(s+s);
        string s1,s2;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                s1+='1';
                s2+='0';
            }else {
                s1+='0';
                s2+='1';
            }
        }
        int result = INT_MAX;
        int flip1 = 0 , flip2 = 0 ;
        int i=0,j=0;
        while(j<2*n){
            if(s1[j]!=s[j])flip1++;
            if(s2[j]!=s[j])flip2++;
            if(j-i+1>n){
                if(s[i]!=s1[i])flip1--;
                if(s[i]!=s2[i])flip2--;
                i++;
            }
            if(j-i+1==n)result = min({result,flip1,flip2});

            j++;
        }
        return result;
    }
};