void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        visited[row][col]=true;
        int n=grid.size();
        int m=grid[0].size();
        int delrows[]={-1,0,+1,0};
        int delcols[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrows[i];
            int ncol=col+delcols[i];
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                dfs(nrow,ncol,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
