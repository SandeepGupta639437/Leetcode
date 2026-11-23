class Solution {
public:
    bool checkString(string s) {
        int x = 1;
        for(char c:s){
            if(c=='b'){
                x = 2;
            }
            if(x==2 && c=='a')return false;
        }
        return true;
    }
};