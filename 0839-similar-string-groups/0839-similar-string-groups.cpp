class Solution {
public:

    vector<int> parent, rank;

    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // compress path
        }
        return parent[x];
    }

    // Union by Rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    // Check if two nodes are in same set
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool isSimilar(string &s1,string &s2){
        int m = s1.length();
        int diff =0;
        for(int i=0;i<m;i++){
            if(s1[i]!=s2[i])diff++;
        }
        return diff==2||diff==0;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        rank.resize(n,0);
        int groupCnt = n;

        for(int i=0;i<n;i++)parent[i]=i;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(find(i)!=find(j) && isSimilar(strs[i],strs[j])){
                    unite(i,j);
                    groupCnt--;
                }
            }
        }
        return groupCnt;
    }
};