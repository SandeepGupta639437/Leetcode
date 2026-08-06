class Solution {
public:
    vector<string>ans;
    int n ;
    void solve(int i,string& digits,string s){
        if(i==n){
            ans.push_back(s);
            return;
        }

        if(digits[i]=='2'){
            solve(i+1,digits,s+'a');
            solve(i+1,digits,s+'b');
            solve(i+1,digits,s+'c');
        }else if(digits[i]=='3'){
            solve(i+1,digits,s+'d');
            solve(i+1,digits,s+'e');
            solve(i+1,digits,s+'f');
        }else if(digits[i]=='4'){
            solve(i+1,digits,s+'g');
            solve(i+1,digits,s+'h');
            solve(i+1,digits,s+'i');
        }else if(digits[i]=='5'){
            solve(i+1,digits,s+'j');
            solve(i+1,digits,s+'k');
            solve(i+1,digits,s+'l');
        }else if(digits[i]=='6'){
            solve(i+1,digits,s+'m');
            solve(i+1,digits,s+'n');
            solve(i+1,digits,s+'o');
        }else if(digits[i]=='7'){
            solve(i+1,digits,s+'p');
            solve(i+1,digits,s+'q');
            solve(i+1,digits,s+'r');
            solve(i+1,digits,s+'s');
        }else if(digits[i]=='8'){
            solve(i+1,digits,s+'t');
            solve(i+1,digits,s+'u');
            solve(i+1,digits,s+'v');
        }else{
            solve(i+1,digits,s+'w');
            solve(i+1,digits,s+'x');
            solve(i+1,digits,s+'y');
            solve(i+1,digits,s+'z');
        }
    }
    vector<string> letterCombinations(string digits) {
        n =  digits.size();
        solve(0,digits,"");
        return ans;
    }
};