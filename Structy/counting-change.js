const countingChange = (amount, coins) => {
  const dp = Array.from(Array(amount+1), () => Array.from(Array(coins.length+1), () => 0));
  dp[0].fill(1);
  
  for(let i=1; i <= amount; i++) {
    for(let j=1; j <= coins.length; j++) {
      if (i - coins[j-1] >= 0)
        dp[i][j] += dp[i-coins[j-1]][j];
    
      dp[i][j] += dp[i][j-1];
    }
  }
  
  return dp[amount][coins.length];
};

module.exports = {
  countingChange,
};
