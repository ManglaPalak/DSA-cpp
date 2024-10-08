//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
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
	    vector<int> ans;
	    while(!q.empty()){
	        int top=q.front();
	        q.pop();
	        ans.push_back(top);
	        for(int i:adj[top]){
	            indegree[i]--;
	            if (indegree[i]==0){
	                q.push(i);
	            }
	        }
	    }
	    return ans;
	}
