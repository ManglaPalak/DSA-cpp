int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> adj[n+1];
    for(auto it: times){
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[k] = 0;
    pq.push({0, k});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int adjnode = it.first;
            int edW = it.second;
            if(dis+edW < dist[adjnode]){
                dist[adjnode] = dis+edW;
                pq.push({dis+edW, adjnode});
            }
        }
    }
    int time=0;
    for(int i=1; i<=n; i++){
        if(dist[i]==INT_MAX){
            return -1;
        }
        time = max(time, dist[i]);
    }
    return time;
}
