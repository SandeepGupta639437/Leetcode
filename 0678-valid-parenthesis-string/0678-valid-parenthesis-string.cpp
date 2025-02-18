class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0; 
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } 
            else if (c == ')') {
                minOpen = max(0, minOpen - 1);
                maxOpen--;
            } 
            else { // '*'
                minOpen = max(0, minOpen - 1);
                maxOpen++;
            }
            
            if (maxOpen < 0) return false;  // Too many ')'
        }
        
        return minOpen == 0;  // If minOpen is 0, it's valid
    }
};
