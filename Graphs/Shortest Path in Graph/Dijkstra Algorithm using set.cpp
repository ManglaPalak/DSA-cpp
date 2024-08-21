//Function to find the shortest distance of all the vertices
//from the source vertex S.
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    vector<int> dist(V,INT_MAX);
    set<pair<int,int>> st;
    dist[S]=0;
    st.insert({0,S});
    while(!st.empty()){
        pair<int,int> it=*(st.begin());
        int di=it.first;
        int node=it.second;
        st.erase(it);
        for(auto i:adj[node]){
            int edgeW=i[1];
            int neigh=i[0];
            if (dist[neigh]>di+edgeW){
                st.erase({dist[neigh],neigh});
                dist[neigh]=di+edgeW;
                st.insert({dist[neigh],neigh});
            }
        }
    }
    return dist;
}
