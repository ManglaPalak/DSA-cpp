int solve(int i,int n,vector<int>& nums,vector<int>& dp){
        if (i>=n){
            return 0;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        int exclude=solve(i+1,n,nums,dp);
        int include=solve(i+2,n,nums,dp)+nums[i];
        dp[i]=max(exclude,include);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums.size(),nums,dp);
    }
