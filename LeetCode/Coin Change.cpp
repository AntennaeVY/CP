class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 1e9));

        for(int i=0; i <= coins.size(); i++) {
            dp[i][0] = 0;
        }

        for(int i=1; i <= coins.size(); i++) {
            for(int j=1; j <= amount; j++) {
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                    continue;  
                }

                // take and repeat coin
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i-1]]);

                // take and not repeat
                dp[i][j] = min(dp[i][j], 1 + dp[i-1][j - coins[i-1]]);

                // skip
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }

        return dp[coins.size()][amount] == 1e9 ? -1 : dp[coins.size()][amount];
    }
};