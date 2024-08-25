class DisjointSet{
    public:
    vector<int> size,parent;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtra=0;
        for(auto i:connections){
            int u=i[0];
            int v=i[1];
            if (ds.findPar(u)==ds.findPar(v)){
                cntExtra++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if (ds.parent[i]==i){
                cnt++;
            }
        }
        if (cntExtra>=cnt-1){
            return cnt-1;
        }
        else{
            return -1;
        }
    }
};
