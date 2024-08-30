int solve(int s,int e,vector<int>& nums,vector<int>& dp){
        if (s>=e){
            return 0;
        }
        if (dp[s]!=-1){
            return dp[s];
        }
        int exc=solve(s+1,e,nums,dp);
        int inc=solve(s+2,e,nums,dp)+nums[s];
        dp[s]=max(exc,inc);
        return dp[s];
    }
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        vector<int> dp1(nums.size(),-1);
        int first=solve(0,nums.size()-1,nums,dp1);
        vector<int> dp2(nums.size(),-1);
        int last=solve(1,nums.size(),nums,dp2);
        return max(first,last);
    }
