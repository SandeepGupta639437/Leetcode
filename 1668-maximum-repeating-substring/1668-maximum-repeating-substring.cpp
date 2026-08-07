class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string word1 = word;
        int i=0;
        while(true){
            if(sequence.find(word1)!=string::npos){
                word1+=word;
                i++;
            }else return i;
        }
        return i;
    }
};