class Solution {
public:
    bool checkZeroOnes(string s) {
        int nO1 = 1, nO0 = 1;
        int mO1 = 1, mO0 = 1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1] && s[i]=='1'){
                nO1++;
                mO0 = max(mO0,nO0);
                mO1 = max(mO1,nO1);
            }
            if(s[i]!=s[i+1]){
                nO0=nO1 =1;
            }
            if(s[i]==s[i+1] && s[i]=='0'){
                nO0++;
                mO0 = max(mO0,nO0);
                mO1 = max(mO1,nO1);
            }
        }
        if( s.size()==1 && s[0]=='1')return true;
        return mO1>mO0 ;
    }
};