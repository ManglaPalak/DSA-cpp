bool dfs(int node,int col,vector<vector<int>>& graph,vector<int>& color){
    color[node]=col;
    for(int i:graph[node]){
        if (color[i]==-1){
            if (dfs(i,!col,graph,color)==false){
                return false;
            }
        }
        if (color[i]==col){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(),-1);
    for(int i=0;i<graph.size();i++){
        if (color[i]==-1){
            if (dfs(i,0,graph,color)==false){
                return false;
            }
        }
    }
    return true;
}
