class Solution {
public:
    int bits(int i){
        int j=0;
        string s= bitset<32>(i).to_string();
        for(int i=0;i<32;i++){
            if(s[i]=='1')j++;
        }
        return j;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn>8)return {};
        vector<string>ans;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if((bits(i)+bits(j))==turnedOn){
                    string s=to_string(i)+":";
                    if(j>=10)s+=to_string(j);
                    else s+="0"+to_string(j);
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};