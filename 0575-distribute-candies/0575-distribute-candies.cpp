class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
         set<int> s;  
         int n=candyType.size();
        for (int num : candyType) {
            s.insert(num);
        }
        if(s.size()>n/2) return n/2;
        else{
            return s.size();
        }
    }
};