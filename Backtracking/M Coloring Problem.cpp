bool isSafe(vector<vector<int>>& mat,vector<int>& color,int node,int col){
    for(int i=0;i<mat.size();i++){
        if (i!=node && mat[i][node]==1 && color[i]==col){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& mat,int m,int node,vector<int>& color){
    if (node==mat.size()){
        return true;
    }
    for(int i=1;i<=m;i++){
        if (isSafe(mat,color,node,i)){
            color[node]=i;
            if (solve(mat,m,node+1,color)){
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int> color(mat.size(),0);
    if (solve(mat,m,0,color)){
        return "YES";
    }
    return "NO";
}
