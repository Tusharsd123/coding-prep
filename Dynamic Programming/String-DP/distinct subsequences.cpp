 /*Explanation to the state transition function

dp[i][j] = dp[i-1][j] when s[i-1] != t[j-1] or dp[i][j] = dp[i-1][j] + dp[i-1][j-1] when s[i-1] == t[j-1],
dp[i][j] represents the number of distinct subsequences for s[0, i-1] and t[0, t-1];

We first keep in mind that s is the longer string [0, i-1], t is the shorter substring [0, j-1]. We can assume t is fixed, and s is increasing in character one by one (this is the key point).

For example:
t : ab--> ab --> ab --> ab
s: a --> ac --> acb --> acbb

The first case is easy to catch. When the new character in s, s[i-1], is not equal with the head char in t, t[j-1], we can no longer increment the number of distinct subsequences, it is the same as the situation before incrementing the s, so dp[i][j] = dp[i-1][j].

However, when the new incrementing character in s, s[i-1] is equal with t[j-1], which contains two case:

We don't match those two characters, which means that it still has original number of distinct subsequences, so dp[i][j] = dp[i-1][j].
We match those two characters, in this way. dp[i][j] = dp[i-1][j-1];
Thus, including both two case, dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

TALKING IS CHEAP:

'''
*/

public int numDistinct(String s, String t) {
    int n = s.length();
    int m = t.length();
    
    int[][] dp = new int[n+1][m+1];
    
    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }
    
    for (int j = 1; j < m+1; j++) {
        dp[0][j] = 0;
    }
    
    for (int j = 1; j < m+1; j++) {
        for (int i = 1; i < n+1; i++) {
            dp[i][j] = dp[i-1][j];
            if (s.charAt(i-1) == t.charAt(j-1)) {
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }
    
    return dp[n][m];
}
