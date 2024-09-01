int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if (i==0 && j==0){
            return 1;
        }
        if (i<0 || j<0 || obstacleGrid[i][j]==1){
            return 0;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=0;
        int up=0;
        if (i>0){
            if (obstacleGrid[i-1][j]==0){
                up=solve(i-1,j,obstacleGrid,dp);
            }
        }
        if (j>0){
            if (obstacleGrid[i][j-1]==0){
                left=solve(i,j-1,obstacleGrid,dp);
            }
        }
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if (obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
