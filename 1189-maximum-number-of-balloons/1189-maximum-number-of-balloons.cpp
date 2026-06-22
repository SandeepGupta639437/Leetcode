class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int N=text.length();
        int countb=0,counta=0,countl=0,counto=0,countn=0;
        for(int i=0;i<N;i++){
            if(text[i]=='b')countb++;
            if(text[i]=='a')counta++;
            if(text[i]=='l')countl++;
            if(text[i]=='o')counto++;
            if(text[i]=='n')countn++;
        }
        int b=countb;
        int a=counta;
        int l=countl/2;
        int o=counto/2;
        int n=countn;
        int ans1=min({b,a,l,o,n});
        return ans1;
    }
};