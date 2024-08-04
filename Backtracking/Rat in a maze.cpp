#include <bits/stdc++.h> 
bool isSafe(int n, int x, int y, vector<vector<int>> &arr, 
        vector<vector<int>> &visited){
    if ((x>=0 && x<n) && (y>=0 && y<n)){
        if (arr[x][y]==1 && visited[x][y]==0){
            return true;
        }
    }
    return false;
}
void solve(vector<vector<int>> &arr, int n, int x, int y, 
        vector<vector<int>> &visited, vector<string> &ans, string &op){
    if (x==(n-1) && y==(n-1)){
        ans.push_back(op);
        return;
    }
    visited[x][y]=1;

    //down
    int newx=x+1;
    int newy=y;
    if (isSafe(n,newx,newy,arr,visited)){
        op.push_back('D');
        solve(arr,n,newx,newy,visited,ans,op);
        op.pop_back();
    }

    //left
    newx=x;
    newy=y-1;
    if (isSafe(n,newx,newy,arr,visited)){
        op.push_back('L');
        solve(arr,n,newx,newy,visited,ans,op);
        op.pop_back();
    }

    //right
    newx=x;
    newy=y+1;
    if (isSafe(n,newx,newy,arr,visited)){
        op.push_back('R');
        solve(arr,n,newx,newy,visited,ans,op);
        op.pop_back();
    }

    //up
    newx=x-1;
    newy=y;
    if (isSafe(n,newx,newy,arr,visited)){
        op.push_back('U');
        solve(arr,n,newx,newy,visited,ans,op);
        op.pop_back();
    }

    visited[x][y]=0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    string op="";
    if (arr[0][0]==0){
        return ans;
    }
    vector<vector<int>> visited=arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    solve(arr,n,0,0,visited,ans,op);
    return ans;
}
