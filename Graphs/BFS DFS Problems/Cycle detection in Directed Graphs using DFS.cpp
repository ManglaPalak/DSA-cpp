bool dfs(int i,vector<int> adj[],vector<bool>& visited,vector<bool>& pathVisited){
        visited[i]=true;
        pathVisited[i]=true;
        for(int j:adj[i]){
            if (!visited[j]){
                if (dfs(j,adj,visited,pathVisited)==true){
                    return true;
                }
            }
            else if (pathVisited[j]){
                return true;
            }
        }
        pathVisited[i]=false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> pathVisited(V,false);
        for(int i=0;i<V;i++){
            if (!visited[i]){
                if (dfs(i,adj,visited,pathVisited)==true){
                    return true;
                }
            }
        }
        return false;
    }
