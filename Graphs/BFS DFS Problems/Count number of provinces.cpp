void dfs(vector<vector<int>>& adj,int i,vector<bool>& visited){
        visited[i]=true;
        for(int j:adj[i]){
            if (!visited[j]){
                dfs(adj,j,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n,false);
        int province=0;
        for(int i=0;i<n;i++){
            if (!visited[i]){
                dfs(adj,i,visited);
                province++;
            }
        }
        return province;
    }
