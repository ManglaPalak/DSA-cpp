#include <bits/stdc++.h> 
// using Kahn algorithm
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // step1: create adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    // step2: calculate indegree
    vector<int> indegree(v,0);
    for(auto i:adj){
        for(int nodes:i.second){
            indegree[nodes]++;
        }
    }
    // step3: find indegree 0;
    queue<int> q;
    for(int i=0;i<v;i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }
    // step4: indegree updation and vector ans formation
    vector<int> ans;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(int neigh:adj[top]){
            indegree[neigh]--;
            if (indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }
    return ans;
}
/*
// using DFS
void topoSort(int node,vector<bool>& visited,stack<int>& st,
            unordered_map<int,vector<int>>& adj){
    visited[node]=true;
    for(int i:adj[node]){
        if (!visited[i]){
            topoSort(i, visited, st, adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

    //dfs call
    vector<bool> visited(v);
    stack<int> st;
    for(int i=0;i<v;i++){
        if (!visited[i]){
            topoSort(i,visited,st,adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
*/
