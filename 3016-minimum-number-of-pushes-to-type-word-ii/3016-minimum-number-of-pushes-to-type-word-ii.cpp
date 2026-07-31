class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        nth_element(freq.begin(), freq.begin()+7, end(freq), greater<int>());
        nth_element(freq.begin()+8, freq.begin()+15, end(freq), greater<int>());
        nth_element(freq.begin()+16, freq.begin()+23, end(freq), greater<int>());

        int sum = 0,i=0;

        for (int f : freq) {
            sum = sum + f * (i / 8 + 1);
            i++;
        }
        return sum;
    }
};