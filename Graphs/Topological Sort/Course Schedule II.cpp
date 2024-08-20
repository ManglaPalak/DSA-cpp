vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(int j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        int cnt=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            cnt++;
            for(int i:adj[top]){
                indegree[i]--;
                if (indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if (cnt==numCourses){
            return ans;
        }
        else{
            return {};
        }
    }
