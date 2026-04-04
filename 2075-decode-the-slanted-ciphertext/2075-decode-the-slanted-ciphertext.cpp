class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0) return "";
        
        int len = encodedText.length();
        int col = len / rows;
        
        string ans = "";
        
        for (int c=0;c<col;c++) {
            int i=0,j=c;
            while (i < rows && j < col) {
                ans+=encodedText[i*col+j];
                i++;
                j++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};