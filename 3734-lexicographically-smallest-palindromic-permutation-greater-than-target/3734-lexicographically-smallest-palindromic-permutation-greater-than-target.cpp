class Solution {
public:
    string result = "";
    int n;
    char middle;

    bool solve(string &curr, vector<int> &count, string &target, int i, bool greater) {

        if(i == n){
            // Construct the complete palindrome
            string temp = curr;
            reverse(temp.begin(), temp.end());

            string candidate;

            if(middle != '\0')
                candidate = curr + string(1, middle) + temp;
            else
                candidate = curr + temp;

            if(candidate > target){
                result = curr;
                return true;
            }

            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){

            if(count[ch - 'a'] == 0) continue;

            if(!greater && ch < target[i]) continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target, i + 1, isGreater)) return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target1) {

        result = "";

        vector<int> count(26, 0);

        for(char ch : s) count[ch - 'a']++;

        int uniqCnt = 0;
        middle = '\0';

        for(int i = 0; i < 26; i++){
            if(count[i] % 2){
                uniqCnt++;
                middle = 'a' + i;
            }
            count[i] /= 2;
        }

        if(uniqCnt > 1) return "";

        n = s.length() / 2;

        string curr;

        if(!solve(curr, count, target1, 0, false)) return "";

        string temp = result;
        reverse(temp.begin(), temp.end());

        if(s.length() % 2) return result + string(1, middle) + temp;

        return result + temp;
    }
};