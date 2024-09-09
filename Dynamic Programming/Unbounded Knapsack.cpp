int solve(int i,int W,int val[], int wt[],vector<vector<int>>& dp){
        if (i==0){
            return (W/wt[0])*val[0];
        }
        if (dp[i][W]!=-1){
            return dp[i][W];
        }
        int notTake=0+solve(i-1,W,val,wt,dp);
        int take=0;
        if (W>=wt[i]){
            take=val[i]+solve(i,W-wt[i],val,wt,dp);
        }
        return dp[i][W]=max(notTake,take);
    }
    int knapSack(int N, int W, int val[], int wt[]){
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
