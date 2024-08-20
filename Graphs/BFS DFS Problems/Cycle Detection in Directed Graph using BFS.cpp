// Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cnt++;
            for(int i:adj[top]){
                indegree[i]--;
                if (indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if (cnt==V){
            return false;
        }
        else{
            return true;
        }
    }
