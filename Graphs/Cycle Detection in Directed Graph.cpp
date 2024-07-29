bool dfs(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited,
unordered_map<int,vector<int>>& adj){
  visited[node]=true;
  dfsVisited[node]=true;
  for(int i:adj[node]){
    if (!visited[i]){
      bool ans=dfs(i,visited,dfsVisited,adj);
      if (ans){
        return true;
      }
    }
    else if (dfsVisited[i]){
      return true;
    }
  }
  dfsVisited[node]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,vector<int>> adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;
  for(int i=1;i<=n;i++){
    if (!visited[i]){
      bool ans=dfs(i,visited,dfsVisited,adj);
      if (ans){
        return true;
      }
    }
  }
  return false;
}
