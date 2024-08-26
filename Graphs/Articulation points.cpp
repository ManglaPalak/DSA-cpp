private:
    int timer=1;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& vis,vector<int>& tin,
                vector<int>& low,vector<int>& mark){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node]){
            if (it==parent){
                continue;
            }
            if (vis[it]==0){
                dfs(it,node,adj,vis,tin,low,mark);
                low[node]=min(low[node],low[it]);
                if (low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else if (vis[it]==1){
                low[node]=min(low[node],tin[it]);
            }
        }
        if (child>1 && parent==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> tin(V);
        vector<int> low(V);
        vector<int> vis(V,0);
        vector<int> mark(V,0);
        for(int i=0;i<V;i++){
            if (!vis[i]){
                dfs(i,-1,adj,vis,tin,low,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if (mark[i]==1){
                ans.push_back(i);
            }
        }
        if (ans.size()==0){
            return {-1};
        }
        return ans;
    }
