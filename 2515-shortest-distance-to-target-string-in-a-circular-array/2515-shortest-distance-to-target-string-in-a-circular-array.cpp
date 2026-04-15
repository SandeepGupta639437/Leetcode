class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans =   n+2;
        for(int i=0;i<n;i++){
           if(words[i]==target){
                if(startIndex>=i){
                    ans = min(ans,startIndex - i);
                    ans = min(ans,+i+n-startIndex);
                }else{
                    ans = min(ans,i - startIndex);
                    ans = min(ans,startIndex+n-i); 
                }
           }
        }
        if(ans==n+2)return -1;
        return ans;
    }
};