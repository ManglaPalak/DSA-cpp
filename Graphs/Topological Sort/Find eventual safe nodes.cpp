vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adjRev(graph.size());
        vector<int> indegree(graph.size());
        for(int i=0;i<graph.size();i++){
            // i -> j
            // j -> i
            for(int j:graph[i]){
                adjRev[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            safeNodes.push_back(top);
            for(int i:adjRev[top]){
                indegree[i]--;
                if (indegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
