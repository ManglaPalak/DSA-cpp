void dfs(int row,int col,vector<vector<char>>& board,vector<vector<bool>>& visited){
    visited[row][col]=true;
    int n=board.size();
    int m=board[0].size();
    int delrows[]={-1,0,+1,0};
    int delcols[]={0,+1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=row+delrows[i];
        int ncol=col+delcols[i];
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==false && board[nrow][ncol]=='O'){
            dfs(nrow,ncol,board,visited);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n=board.size();
    int m=board[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    // first and last columns
    for(int i=0;i<n;i++){
        if (board[i][0]=='O'){
            visited[i][0]=true;
            dfs(i,0,board,visited);
        }
        if (board[i][m-1]=='O'){
            visited[i][m-1]=true;
            dfs(i,m-1,board,visited);
        }
    }
    // first and last rows
    for(int i=0;i<m;i++){
        if (board[0][i]=='O'){
            visited[0][i]=true;
            dfs(0,i,board,visited);
        }
        if (board[n-1][i]=='O'){
            visited[n-1][i]=true;
            dfs(n-1,i,board,visited);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (visited[i][j]==false && board[i][j]=='O'){
                board[i][j]='X';
            }
        }
    }
}
