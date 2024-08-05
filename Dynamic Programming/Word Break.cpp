bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++){
            for(string word:wordDict){
                int start=i-word.length();
                if (start>=0 && dp[start] && s.substr(start,word.length())==word){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
