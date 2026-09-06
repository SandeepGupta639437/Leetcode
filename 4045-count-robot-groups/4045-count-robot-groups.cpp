class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        //for t0
        stack<pair<int,int>>st;
        int n = position.size();
        st.push({position[0],speed[0]});

        for(int i=1;i<n;i++){
            auto [x,y] = st.top();
            if(position[i]-x <= distance){
                st.pop();
            }
            st.push({position[i],speed[i]});
        }

        vector<pair<int,int>>afterT;
        while(!st.empty()){
            afterT.push_back(st.top());
            st.pop();
        }

        reverse(begin(afterT),end(afterT));

        stack<pair<int,int>>finalSt;
        if(afterT.size()>0)finalSt.push(afterT[0]);

        for(int i=1;i<afterT.size();i++){
            auto [x,y] = afterT[i];
            auto [X,Y] = finalSt.top();

            if(Y>y){
                finalSt.pop();
            }
            while(!finalSt.empty() && finalSt.top().second > y){
                finalSt.pop();
            }
            finalSt.push({x,y});
            
        }
        return finalSt.size();
    }
};