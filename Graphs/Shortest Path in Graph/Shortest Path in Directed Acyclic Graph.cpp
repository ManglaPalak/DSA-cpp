vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    vector<vector<pair<int,int>>> adj(N);
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj[u].push_back({v,w});
    }
    vector<int> dist(N,INT_MAX);
    dist[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto i:adj[top]){
            if (dist[i.first]>dist[top]+i.second){
                dist[i.first]=dist[top]+i.second;
                q.push(i.first);
            }
        }
    }
    for(int i=0;i<N;i++){
        if (dist[i]==INT_MAX){
            dist[i]=-1;
        }
    }
    return dist;
}
