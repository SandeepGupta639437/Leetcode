class Solution {
public:
    bool isBalanced(string num) {
        int sume=0;
        int sumo=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0)sumo+=num[i]-'0';
            else sume+=num[i]-'0';
        }
        if(sumo==sume)return true;
        return false;
    }
};