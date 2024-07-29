#include <bits/stdc++.h> 
#include<unordered_map>
#include<set>
#include<vector>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // step1: create adjacency list
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // step2: create distance vector
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    dist[source]=0;

    // step3: create set with node (distance,node)
    set<pair<int,int>> s;
    s.insert(make_pair(0,source));

    while(!s.empty()){
        pair<int,int> top=*(s.begin());
        int nodeDist=top.first;
        int node=top.second;
        s.erase(s.begin());

        // step4: tarverse the neighbours
        for(auto neigh:adj[node]){
            if (dist[top.second]+neigh.second < dist[neigh.first]){
                auto record=s.find(make_pair(dist[neigh.first],neigh.first));
                if (record!=s.end()){
                    s.erase(record);
                }
                dist[neigh.first]=dist[top.second]+neigh.second;
                s.insert(make_pair(dist[neigh.first],neigh.first));
            }
        }
    }
    return dist;
}

/*
Sample input 1
2
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
Sample output 1
0 4 1 2 5
0 5 8 7
*/
