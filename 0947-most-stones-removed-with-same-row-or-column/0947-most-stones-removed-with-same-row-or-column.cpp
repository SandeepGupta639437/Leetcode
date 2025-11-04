class Solution {
public:
    void dfs(vector<vector<int>>& stones,int index, vector<bool>&visited){
        visited[index]=true;

        for(int i=0;i<stones.size();i++){
            if(visited[i]==false && ((stones[i][0]==stones[index][0])||(stones[i][1]==stones[index][1]))){
               dfs(stones,i,visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
      int n=stones.size();
      
      vector<bool>visited(n,false);

      int group=0;

      for(int i=0;i<n;i++){
        if(visited[i]==true)continue;
        else{
            dfs(stones,i,visited);
            group++;
        }
      }
      return n-group;





    //   map<int,int>mppr;
    //   map<int,int>mppc;
    //   for(int i=0;i<n;i++){
    //     mppr[stones[i][0]]=mppr[stones[i][0]]=1;
    //     mppc[stones[i][0]]=mppc[stones[i][0]]=1;
    //   }
    //   int left=0;
    //   for(int i=0;i<n;i++){
    //     if(mppr[stones[i][0]]==2 || mppc[stones[i][1]]==2){
    //        mppr[stones[i][0]]=2;
    //        mppc[stones[i][1]]=2;
    //        continue;
    //     }
    //     else{
    //         left++;
    //         mppr[stones[i][0]]=2;
    //         mppc[stones[i][1]]=2;
    //     }
    //   }
    //   return n-left;
    }
};