vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(N,1e9);
        dist[src]=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        while(!q.empty()){
            int top=q.front().first;
            int di=q.front().second;
            q.pop();
            for(int i:adj[top]){
                if (dist[i]>di+1){
                    dist[i]=di+1;
                    q.push({i,dist[i]});
                }
            }
        }
        for(int i=0;i<N;i++){
            if (dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
