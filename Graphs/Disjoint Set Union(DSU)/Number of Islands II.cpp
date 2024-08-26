class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findPar(int node){
        if (node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if (pu==pv){
            return;
        }
        if (size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> ans;
        int cnt=0;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if (vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int dr[]={-1,0,+1,0};
            int dc[]={0,+1,0,-1};
            for(int i=0;i<4;i++){
                int adjr=row+dr[i];
                int adjc=col+dc[i];
                if (adjr>=0 && adjr<n && adjc>=0 && adjc<m && vis[adjr][adjc]==1){
                    int nodeNo=row*m+col;
                    int adjNodeNo=adjr*m+adjc;
                    if (ds.findPar(nodeNo)!=ds.findPar(adjNodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
