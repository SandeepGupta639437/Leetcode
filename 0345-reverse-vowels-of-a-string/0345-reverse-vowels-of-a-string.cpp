class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(!isVowel(s[i])){
                i++;
            }
            else if(!isVowel(s[j])){
                j--;
            }
            else{
                char v=s[i];
                s[i]=s[j];
                s[j]=v;
                i++;
                j--;
            }


        }
        return s;
        
    }
};