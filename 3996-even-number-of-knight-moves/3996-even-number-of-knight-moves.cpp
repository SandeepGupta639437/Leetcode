class Solution {
public:
    bool visited[9][9][2];

    bool solve(int i,int j,int I,int J,int cnt){

        if(i < 0 || i >= 8 || j < 0 || j >= 8)
            return false;

        if(i == I && j == J)
            return (cnt % 2 == 0);

        if(visited[i][j][cnt % 2])
            return false;

        visited[i][j][cnt % 2] = true;

        return solve(i-2,j+1,I,J,cnt+1) ||
            solve(i-2,j-1,I,J,cnt+1) ||
            solve(i-1,j-2,I,J,cnt+1) ||
            solve(i+1,j-2,I,J,cnt+1) ||
            solve(i+2,j-1,I,J,cnt+1) ||
            solve(i+2,j+1,I,J,cnt+1) ||
            solve(i+1,j+2,I,J,cnt+1) ||
            solve(i-1,j+2,I,J,cnt+1);
    }

    bool canReach(vector<int>& start, vector<int>& target) {
        memset(visited,0,sizeof(visited));
        return solve(start[0],start[1],target[0],target[1],0);
    }
};