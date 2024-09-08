bool solve(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
        if (target==0){
            return true;
        }
        if (i==0){
            return nums[i]==target;
        }
        if (dp[i][target]!=-1){
            return dp[i][target];
        }
        bool notTake=solve(i-1,nums,target,dp);
        bool take=false;
        if (target>=nums[i]){
            take=solve(i-1,nums,target-nums[i],dp);
        }
        return dp[i][target]=notTake | take;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if (total%2 != 0){
            return false;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(total/2+1,-1));
        return solve(nums.size()-1,nums,total/2,dp);
    }
