#include<unordered_map>
#include<queue>
#include<vector>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,vector<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	unordered_map<int,bool> visited(n);
	unordered_map<int,int> parent(n);
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		for(int i:adj[top]){
			if (!visited[i]){
				visited[i]=true;
				parent[i]=top;
				q.push(i);
			}
		}
	}
	vector<int> ans;
	int curr=t;
	ans.push_back(t);
	while(curr!=s){
		curr=parent[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
