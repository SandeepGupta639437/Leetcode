class TreeAncestor{
public:
  vector<vector<int>>Ancestor;
  int rows , cols;

  TreeAncestor(int n,vector<int>parent){
    rows = n;
    cols = log2(n) + 1;
    Ancestor.resize(rows,vector<int>(cols,-1));

    for(int i=0;i<n;i++){
      Ancestor[i][0] = parent[i];
    }

    for (int j = 1; j < cols; j++) {
        for (int node = 0; node < rows; node++) {
            if (Ancestor[node][j - 1] != -1)
                Ancestor[node][j] = Ancestor[Ancestor[node][j - 1]][j - 1];
        }
    }
  }

  int getKthAncestor(int node,int k){
    for(int j=0;j<cols;j++){
      if(k& (1<<j)){
        node =  Ancestor[node][j];
        if(node == -1)return -1;
      }
    }
    return node;
  }

};

