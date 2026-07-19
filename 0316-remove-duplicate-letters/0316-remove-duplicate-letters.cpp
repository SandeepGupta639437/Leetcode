class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int>lastIdx(26,0);

        for(int i=0;i<n;i++){
            lastIdx[s[i]-'a'] = i;
        }

        stack<char>st;
        vector<bool>inStack(26,false);
        st.push(s[0]);
        inStack[s[0]-'a'] = true;
        for(int i=1;i<n;i++){
            if(!inStack[s[i]-'a']){
                while(!st.empty() && st.top()-'a' > s[i]-'a' && lastIdx[st.top()-'a'] > i){
                    inStack[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(s[i]);
                inStack[s[i]-'a'] =true;
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};