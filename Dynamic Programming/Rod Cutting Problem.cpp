int solve(int i,int N,int price[],vector<vector<int>>& dp){
        if (i==0){
            return N*price[0];
        }
        if (dp[i][N]!=-1){
            return dp[i][N];
        }
        int notTake=0+solve(i-1,N,price,dp);
        int take=INT_MIN;
        int rod=i+1;
        if (rod<=N){
            take=price[i]+solve(i,N-rod,price,dp);
        }
        return dp[i][N]=max(notTake,take);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
