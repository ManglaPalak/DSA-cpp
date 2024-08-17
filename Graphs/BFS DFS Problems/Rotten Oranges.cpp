int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        int fresh=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]==1){
                    fresh++;
                    visited[i][j]=1;
                }
                else if (grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=2;
                }
            }
        }
        while(!q.empty()){
            int s=q.size();
            bool rot=false;
            for(int i=0;i<s;i++){
                pair<int,int> top=q.front();
                q.pop();
                int row=top.first;
                int col=top.second;
                // left
                if (row>=0 && row<n && col-1>=0){
                    if (visited[row][col-1]==1){
                        visited[row][col-1]=2;
                        rot=true;
                        fresh--;
                        q.push({row,col-1});
                    }
                }
                // right
                if (row>=0 && row<n && col+1<m){
                    if (visited[row][col+1]==1){
                        visited[row][col+1]=2;
                        rot=true;
                        fresh--;
                        q.push({row,col+1});
                    }
                }
                // up
                if (row-1>=0 && col>=0 && col<m){
                    if (visited[row-1][col]==1){
                        visited[row-1][col]=2;
                        rot=true;
                        fresh--;
                        q.push({row-1,col});
                    }
                }
                // down
                if (row+1<n && col>=0 && col<m){
                    if (visited[row+1][col]==1){
                        visited[row+1][col]=2;
                        rot=true;
                        fresh--;
                        q.push({row+1,col});
                    }
                }
            }
            if (rot==true){
                time++;
            }
        }
        if (fresh>0){
            return -1;
        }
        return time;
    }
