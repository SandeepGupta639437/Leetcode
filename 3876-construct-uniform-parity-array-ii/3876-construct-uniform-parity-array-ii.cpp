class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mini = *min_element(begin(nums1),end(nums1));
        if(mini%2==1)return true; // agr sbse chota element odd hai to hum sbko odd bna skte hai 

        for(int x : nums1)if(x%2==1)return false; // age pehla odd nhi hai to agr koi aur odd hoga to possible nhi hoga
        
        return true;
        
    }
};