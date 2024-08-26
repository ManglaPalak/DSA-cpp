public:
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& tin,vector<int>& low,vector<vector<int>>& bridges){
        vis[node]=true;
        low[node]=tin[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if (it==parent){
                continue;
            }
            if (vis[it]==0){
                dfs(it,node,adj,vis,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                if (low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else if (vis[it]==1){
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        vector<bool> vis(n,false);
        dfs(0,-1,adj,vis,tin,low,bridges);
        return bridges;
    }
