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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if (grid[row][col]==0){
                    continue;
                }
                int dr[]={-1,0,+1,0};
                int dc[]={0,+1,0,-1};
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                    if (nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int node=row*n+col;
                        int adjNode=nr*n+nc;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if (grid[row][col]==1){
                    continue;
                }
                int dr[]={-1,0,+1,0};
                int dc[]={0,+1,0,-1};
                set<int> comp;
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                    if (nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        comp.insert(ds.findPar(nr*n+nc));
                    }    
                }
                int sumTotal=0;
                for(auto i:comp){
                    sumTotal+=ds.size[i];
                }
                maxi=max(maxi,sumTotal+1);
            }
        }
        for(int cell=0;cell<n*n;cell++){
            maxi=max(maxi,ds.size[ds.findPar(cell)]);
        }
        return maxi;
    }
};
