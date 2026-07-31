class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        nth_element(freq.begin(), freq.begin()+7, end(freq), greater<int>());
        nth_element(freq.begin()+8, freq.begin()+15, end(freq), greater<int>());
        nth_element(freq.begin()+16, freq.begin()+23, end(freq), greater<int>());

        int i=0; 
        return accumulate(freq.begin(), freq.end(), 0,  [&i](int sum, int f){
            return sum+=(f*(i++/8+1));
        });


        return ans;
    }
};