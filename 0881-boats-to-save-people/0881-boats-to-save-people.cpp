class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int l = 0,r = people.size()-1;
        int boat = 0;
        while(l<=r){
            if(people[l]+people[r]>limit){
                boat++;
                r--;
            }else{
                boat++;
                l++;
                r--;
            }
        }
        return boat;
    }
};