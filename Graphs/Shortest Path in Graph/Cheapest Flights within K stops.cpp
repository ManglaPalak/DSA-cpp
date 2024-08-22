int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<flights.size();i++){
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }
    vector<int> dist(n,INT_MAX);
    queue<pair<int,pair<int,int>>> q;
    dist[src]=0;
    q.push({0,{src,0}});
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        int stops=top.first;
        int node=top.second.first;
        int cost=top.second.second;
        if (stops>k){
            continue;
        }
        for(auto j:adj[node]){
            int adjNode=j.first;
            int edgeW=j.second;
            if (edgeW+cost < dist[adjNode] && stops<=k){
                dist[adjNode]=edgeW+cost;
                q.push({stops+1,{adjNode,edgeW+cost}});
            }
        }
    }
    if (dist[dst]==INT_MAX){
        return -1;
    }
    return dist[dst];
}
