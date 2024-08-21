//Function to find the shortest distance of all the vertices
//from the source vertex S.
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty()){
        int dst=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            int edgeW=i[1];
            int endnode=i[0];
            if (dist[endnode]>dst+edgeW){
                dist[endnode]=dst+edgeW;
                pq.push({dist[endnode],endnode});
            }
        }
    }
    return dist;
}
