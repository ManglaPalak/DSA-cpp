#include <bits/stdc++.h> 
#include<unordered_map>
#inlcude<vector>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    // step1: create adjacency list
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    // step2: create 3 vectors key,mst,parent
    vector<int> dist(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);

    // step3: traverse the graph
    // starting with 1st node
    dist[1]=0;
    parent[1]=-1;
    for(int i=1;i<=n;i++){
        int mini=INT_MAX;
        int u;
        // find minimum distance in key
        for(int i=1;i<=n;i++){
            if (mst[i]==false && dist[i]<mini){
                u=i;
                mini=dist[i];
            }
        }
        mst[u]=true;
        for(auto neigh:adj[u]){
            int v=neigh.first;
            int w=neigh.second;
            if (mst[v]==false && w<dist[v]){
                parent[v]=u;
                dist[v]=w;
            }
        }
    }
    // step4: create the answer vector
    vector<pair<pair<int,int>,int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back(make_pair(make_pair(parent[i],i),dist[i]));
    }
    return ans;
}

/*
Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5
Explanation of Input 1 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) with weight 3 and (2,5) with weight 5.
*/
