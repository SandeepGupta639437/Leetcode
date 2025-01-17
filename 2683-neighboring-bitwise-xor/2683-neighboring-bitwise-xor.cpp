class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int flag=0;
       int n=derived.size();
        if(n<2){
            if(derived[0])return false;
            else return true;
        }
        else if(derived[0]){
           vector<int>a1(n);
           a1[0]=1;a1[1]=0;
           for(int i=2;i<n;i++){
            a1[i]=a1[i-1]^derived[i-1];
           }
           if(a1[0]^a1[n-1]==derived[n-1])flag=1;
           vector<int>a2(n);
           a2[0]=0;a2[1]=1;
           for(int i=2;i<n;i++){
            a2[i]=a2[i-1]^derived[i-1];
           }
           if(a2[0]^a2[n-1]==derived[n-1])flag=1;
        }
        else{
           vector<int>a1(n);
           a1[0]=0;a1[1]=0;
           for(int i=2;i<n;i++){
            a1[i]=a1[i-1]^derived[i-1];
           }
           if(a1[0]^a1[n-1]==derived[n-1])flag=1;
           vector<int>a2(n);
           a2[0]=1;a2[1]=1;
           for(int i=2;i<n;i++){
            a2[i]=a2[i-1]^derived[i-1];
           }
           if(a2[0]^a2[n-1]==derived[n-1])flag=1;
        }
        if(flag)return true;
        return false;
    }
};