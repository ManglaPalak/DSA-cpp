int solve(int i,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if (amount==0){
            return 1;
        }
        if (i==0){
            return (amount%coins[i]==0);
        }
        if (dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int notTake=solve(i-1,coins,amount,dp);
        int take=0;
        if (coins[i]<=amount){
            take=solve(i,coins,amount-coins[i],dp);
        }
        return dp[i][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
