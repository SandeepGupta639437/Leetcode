class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size()-1, score = 0;;

        while(l<=r){
            if(power >= tokens[l]) score++, power -= tokens[l], l++;
            else if(score >= 1 && l!=r) score--, power += tokens[r], r--;
            else break;
        }

        return score;
    }
};