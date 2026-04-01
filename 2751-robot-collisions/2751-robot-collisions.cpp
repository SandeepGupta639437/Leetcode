class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int>actual_index(n);
        // for(int i=0;i<n;i++){
        //      actual_index[i]=i; 
        // }
        // or
        iota(begin(actual_index),end(actual_index),0); // 0,1,2,3,4...
        auto lambda = [&](int &i,int &j){
            if(positions[i]<positions[j])return true;
            else return false;
        };
        sort(begin(actual_index),end(actual_index),lambda);

        vector<int>result;
        stack<int>st;

        for(int &currIdx: actual_index){
            if(directions[currIdx] == 'R'){
                st.push(currIdx);
            }else{
                while(!st.empty() && healths[currIdx]>0){
                    int top_idx = st.top();
                    st.pop();

                    if(healths[top_idx] > healths[currIdx]){
                        healths[top_idx] -= 1;
                        healths[currIdx] = 0;
                        st.push(top_idx);
                    }else if(healths[top_idx] < healths[currIdx]){
                        healths[top_idx] = 0;
                        healths[currIdx] -= 1;
                    }else{
                        healths[top_idx] = 0;
                        healths[currIdx] = 0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(healths[i]>0)
               result.push_back(healths[i]);
        }
        return result;
    }
};