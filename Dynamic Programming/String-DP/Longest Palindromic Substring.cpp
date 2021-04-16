string longestPalindrome(string s) {
        int n = s.size();
        if(n==0)return "";
        vector<vector<int>>dp(n,vector<int>(n,0));
        pair<int,int> ans;
        int val = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<=n-1; j++){
                if(i==j)dp[i][j] = 1;
                else{
                    if(s[i]==s[j] && 2+dp[i+1][j-1] == j-i+1){
                        dp[i][j] = 2+dp[i+1][j-1];
                    }
                }
                if(dp[i][j]>=val){
                    val = dp[i][j];
                    ans = {i,j};
                }
            }
        }
        
        return s.substr(ans.first,ans.second-ans.first+1);
    }
