// shortest path in directed acyclic graph of one node to all other nodes

#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,vector<pair<int,int>>> adj; // <src,<dest,weight>>

    void addEdge(int u, int v, int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adj){
            cout<< i.first << " -> ";
            for(auto j:i.second){
                cout<< "(" << j.first << "," << j.second << "), ";
            }
            cout<<endl;
        }
    }
    
    void dfs(int node,unordered_map<int,bool>& visited,stack<int>& st){
        visited[node]=true;
        for(auto i:adj[node]){
            if (!visited[i.first]){
                dfs(i.first,visited,st);
            }
        }
        st.push(node);
    }

    void getShortestPath(int src,vector<int>& dist,stack<int>& st){
        dist[src]=0;
        while(!st.empty()){
            int front=st.top();
            st.pop();
            if (dist[front]!=INT_MAX){
                for(auto i:adj[front]){
                    if (dist[front]+i.second < dist[i.first]){
                        dist[i.first]=dist[front]+i.second;
                    }
                }
            }
        }
    }

};
int main(){
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();
    int n=6;
    stack<int> st;
    unordered_map<int,bool> visited(n);
    for(int i=0;i<n;i++){
        if (!visited[i]){
            g.dfs(i,visited,st);
        }
    }
    vector<int> dist(n);
    int src=1;
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    g.getShortestPath(src,dist,st);
    for(int i=0;i<n;i++){
        cout<< dist[i] << " ";
    }
    cout<<endl;
    return 0;
}
