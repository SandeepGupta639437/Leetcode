class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        set<string> operators = {"+","*","-","/"};
        int n = tokens.size();

        for(int i=0;i<n;i++){
            if(!operators.count(tokens[i])) {
                st.push(stoi(tokens[i]));
            }
            else{
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                if(tokens[i]=="*"){
                    st.push(val1*val2);
                }else if(tokens[i]=="+"){
                    st.push(val1+val2);
                }else if(tokens[i]=="-"){
                    st.push(val2-val1);
                }else if(tokens[i]=="/"){
                    st.push(val2/val1);
                }
            }
        }

        return st.top();
    }
};