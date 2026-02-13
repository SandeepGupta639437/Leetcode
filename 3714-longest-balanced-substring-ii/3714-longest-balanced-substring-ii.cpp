class Solution {
public:
    int helper(string s, char ch1,char ch2){
        int n=s.length();
        int maxL=0;
        unordered_map<int,int>diffMap;
        diffMap[0] = -1;
        int count1 = 0,count2 = 0;
        for(int i=0;i<n;i++){
            if(s[i]!=ch1 && s[i]!=ch2){
                diffMap.clear();
                diffMap[0]=i;
                count1=0;
                count2=0;
                continue;
            }
            if(s[i]==ch1)count1++;
            if(s[i]==ch2)count2++;
            if(count1==count2)maxL=max(maxL,count1+count2);

            int diff= count1-count2;
            if(diffMap.count(diff)){
                maxL = max(maxL , i-diffMap[diff]);
            }else{
                diffMap[diff]=i;
            }
        }
        return maxL;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int maxL=0;
        //Case-1
        //"aaaaaa"
        int count = 1; //s[0]
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                maxL = max(maxL,count);
                count=1;
            }
        }
        maxL= max(maxL,count);

        //Case 2 //(a,b) ,(a,c) , (b,c)

        maxL= max(maxL,helper(s,'a','b'));
        maxL= max(maxL,helper(s,'a','c'));
        maxL= max(maxL,helper(s,'b','c'));

        // Case 3 //(a,b,c)

        int countA=0,countB=0,countC=0;
        unordered_map<string,int>diffMap;
        diffMap["0_0"] = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='a')countA++;
            if(s[i]=='b')countB++;
            if(s[i]=='c')countC++;

            if(countA==countB && countB==countC)maxL=max(maxL,countA+countB+countC);
    
            int diffAB = countA - countB;
            int diffAC = countB - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);
            if(diffMap.count(key)){
                maxL = max( maxL , i - diffMap[key] );
            }
            else {
                diffMap[key]=i;
            }
        }
        return maxL;
    }
};