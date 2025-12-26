class Solution {
public:
    int bestClosingTime(string s) {
        int totalY=0,totalN=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='Y')totalY++;
            else totalN++;
        }
        int currY=0,currN=0,index=0;

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int score=0;
           if(s[i]=='Y'){
            score=totalY-currY+currN;
            currY++;
           } 
           else{
            score=totalY-currY+currN;
            currN++;
           }
           if(ans>score){
             ans=score;
             index=i;
           }
        }
        if(ans>totalN){
            index=n;
        }

    return index;
        
    }
};