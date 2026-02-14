class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size(),ans=0,res=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n-1;i++){
            if(heights[i+1]>heights[i]){
               int diff=heights[i+1]-heights[i];
               pq.push(diff);
               if(pq.size()>ladders){
                int b=pq.top();
                pq.pop();
                bricks-=b;
                if(bricks<0){
                    return i;
                }
               }
               res=i+1;
            }else{
                ans=i+1;
            }
        }
        return max(ans,res);
    }
};