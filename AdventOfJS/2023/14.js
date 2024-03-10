function maxGifts(houses) {
  const dp = houses.slice(0, 2);

  for(const house of houses.slice(2)) {
    dp.push(Math.max(dp[dp.length-1], dp[dp.length-2] + house));
  }

  return dp[dp.length-1];
}
