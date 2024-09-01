int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[n-1][i]=matrix[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n;j++){
            int z=matrix[i][j]+dp[i+1][j];
            if(j-1>=0){
                int x=dp[i+1][j-1]+matrix[i][j];
                z=min(z,x);
            }
            if(j+1<n){
               int x=dp[i+1][j+1]+matrix[i][j];
                z=min(z,x);
            }
            dp[i][j]=z;
             // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[0][i]);
        
    }
    return ans;
}
