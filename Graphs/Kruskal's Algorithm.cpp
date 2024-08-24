class DisjointSet{
    vector<int> parent,size;
    public:
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                int u=i;
                int v=j[0];
                int w=j[1];
                edges.push_back({w,{u,v}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstWt=0;
        for(auto i:edges){
            int wt=i.first;
            int u=i.second.first;
            int v=i.second.second;
            if (ds.findPar(u)!=ds.findPar(v)){
                mstWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};
