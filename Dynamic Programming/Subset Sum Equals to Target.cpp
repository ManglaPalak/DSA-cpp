bool solve(int i,vector<int>& arr, int target,vector<vector<int>>& dp){
        if (target==0){
            return true;
        }
        if (i==0){
            return (arr[i]==target);
        }
        if (dp[i][target]!=-1){
            return dp[i][target];
        }
        bool notTake=solve(i-1,arr,target,dp);
        bool take=false;
        if (target>=arr[i]){
            take=solve(i-1,arr,target-arr[i],dp);
        }
        return dp[i][target]=notTake | take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
        return solve(arr.size()-1,arr,sum,dp); 
    }
