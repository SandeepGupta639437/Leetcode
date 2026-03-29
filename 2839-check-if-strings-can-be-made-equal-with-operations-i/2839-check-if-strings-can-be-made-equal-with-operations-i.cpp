class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string s3=s2;
        if(s1==s2)return true;
        swap(s2[0],s2[2]);
        if(s1==s2)return true;
        swap(s3[1],s3[3]);
        if(s1==s3)return true;
        swap(s2[1],s2[3]);
        if(s1==s2)return true;
        return false;
    }
};