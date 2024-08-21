vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    unordered_map<int,vector<pair<int,int>>> adj;
    
    for(auto vec: edges){
        auto u = vec[0];
        auto v = vec[1];
        auto wt = vec[2];
        
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    vector<int> result(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    
    result[1] = 0;
    pq.push({0,1});
    
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        
        int dist = temp.first;
        int node = temp.second;
        
        for(auto it:adj[node]){
            int adjNode = it.first;
            int new_distance = it.second+dist;
            
            if(new_distance < result[adjNode]){
                result[adjNode] = new_distance;
                pq.push({new_distance,adjNode});
                parent[adjNode] = node;
            }
        }
    }
    
    int destNode = n;
    vector<int> ans;
    
    if(result[destNode] == INT_MAX){
        return {-1};
    }
    
    while(parent[destNode] != destNode){
        ans.push_back(destNode);
        destNode = parent[destNode];
    }
    ans.push_back(1);
    
    ans.push_back(result[n]);
    
    reverse(ans.begin(),ans.end());
    return ans;
}
