class Solution {
public:
    int newrow[4]={-1,0,+1,0};
    int newcol[4]={0,+1,0,-1};
    void dfs(int r,int c, vector<vector<int>>& vis,vector<vector<int>>& grid,int cnt){
        vis[r][c] =1;
        int n= grid.size();
        int m=grid[0].size(); 
        for(int i=0;i<4;i++){
            int nr = r + newrow[i];
            int nc = c + newcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                cnt++;
                dfs(nr,nc,vis,grid,cnt);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        //traverse rows
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid,c);
            }
            //last row
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid,c);
            }
        }
        //traverse columns
        for(int j=0;j<n;j++){
            //first col
            if(!vis[j][0] && grid[j][0]==1){
                dfs(j,0,vis,grid,c);
            }
            //last col
            if(!vis[j][m-1] && grid[j][m-1]==1){
                dfs(j,m-1,vis,grid,c);
            }
        }
        int k=0;
        //travese whole
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    k++;
                }
            }
        }
        return abs(k-c);
    }
};
