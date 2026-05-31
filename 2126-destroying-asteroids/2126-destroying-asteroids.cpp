class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids),end(asteroids));
        int n = asteroids.size();
        long long massN = mass;
        for(auto it:asteroids){
            if(it>massN)return false;
            else  massN+=it;
        }
        return true;
    }
};