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
    int removeStones(vector<vector<int>>& stones) {
        int maxRows=0;
        int maxCols=0;
        int n=stones.size();
        for(auto i:stones){
            maxRows=max(maxRows,i[0]);
            maxCols=max(maxCols,i[1]);
        }
        DisjointSet ds(maxRows+maxCols+1);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int u=it[0];
            int v=it[1]+maxRows+1;
            ds.unionBySize(u,v);
            stoneNodes[u]=1;
            stoneNodes[v]=1;
        }
        int cnt=0;
        for(auto it:stoneNodes){
            if (ds.findPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};
