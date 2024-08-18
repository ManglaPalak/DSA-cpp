// ############################################# USING BFS #################################################################
#include<unordered_map>
#include<queue>
bool isCyclic(int src,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i:adj[top]){
            if (visited[i]==true && i!=parent[top]){
                return true;
            }
            else if (!visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=top;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if (!visited[i]){
            bool ans=isCyclic(i,adj,visited);
            if (ans){
                return "Yes";
            }
        }
    }
    return "No";
}

// ########################################################## USING DFS ########################################################
bool dfs(int i,int parent,vector<int> adj[],vector<bool>& visited){
        visited[i]=true;
        for(int neigh:adj[i]){
            if (!visited[neigh]){
                if (dfs(neigh,i,adj,visited)){
                    return true;
                }
            }
            else if (parent!=neigh){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if (!visited[i]){
                if (dfs(i,-1,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
