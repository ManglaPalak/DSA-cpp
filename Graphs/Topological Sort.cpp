void dfs(int node,vector<int> adj[],vector<bool>& visited,stack<int>& st){
	    visited[node]=true;
	    for(int i:adj[node]){
	        if (!visited[i]){
	            dfs(i,adj,visited,st);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<bool> visited(V,false);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if (!visited[i]){
	            dfs(i,adj,visited,st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
