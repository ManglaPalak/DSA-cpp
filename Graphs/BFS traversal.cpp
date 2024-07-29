vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    queue<int> q;
    vector<bool> visited(n,false);
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(int neighbors:adj[top]){
            if (!visited[neighbors]){
                q.push(neighbors);
                visited[neighbors]=true;
            }
        }
    }
    return ans;
}
