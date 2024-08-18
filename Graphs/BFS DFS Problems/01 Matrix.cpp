vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (mat[i][j]==0){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
            else{
                visited[i][j]=0;
            }
        }
    }
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dist[r][c]=steps;
        for(int i=0;i<4;i++){
            int row=r+delrow[i];
            int col=c+delcol[i];
            if (row>=0 && row<n && col>=0 && col<m && visited[row][col]==0){
                visited[row][col]=1;
                q.push({{row,col},steps+1});
            }
        }
    }
    return dist;
}
