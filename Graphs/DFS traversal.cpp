void dfs(int node,unordered_map<int,list<int>>& adj,vector<bool>& visited,vector<int>& comp){
    comp.push_back(node);
    visited[node]=true;
    for(int i:adj[node]){
        if (!visited[i]){
            dfs(i,adj,visited,comp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if (!visited[i]){
            vector<int> comp;
            dfs(i,adj,visited,comp);
            ans.push_back(comp);
        }
    }
    return ans;
}
