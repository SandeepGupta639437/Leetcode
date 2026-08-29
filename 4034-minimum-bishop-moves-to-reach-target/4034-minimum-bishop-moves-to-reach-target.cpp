class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
       int diffx = abs(source[0]-target[0]);
       int diffy = abs(source[1]-target[1]); 

       if(diffx == diffy)return 1;

       if(diffx%2 == diffy%2)return 2;

       return -1;
    }
};