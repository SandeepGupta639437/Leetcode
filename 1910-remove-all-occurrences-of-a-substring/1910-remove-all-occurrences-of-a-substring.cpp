class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t index = s.find(part);  //long long ====size_t & s.find(part) gives index from which it occuurs
        while (index != string::npos) {   // string::npos meaning not found at anyy index or ,means no index
            s.erase(index, part.length());  //s.erase(index, part.length()) removes part from s at the position index.
            index = s.find(part); // same as Line 4.
        }
        return s;
    }
};