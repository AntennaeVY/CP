const minChange = (amount, coins, cache = {}) => {
  if (amount == 0)
    return 0;
  
  if (cache[amount] !== undefined) 
    return cache[amount];
  
  let min = Infinity;
  
  for (const coin of coins) {
    if (amount - coin < 0) 
      continue;
    
    const numCoins = minChange(amount-coin, coins, cache);
    
    if (numCoins == -1) 
      continue;
    
    min = Math.min(min, 1 + numCoins);
  }
  
  if (min === Infinity) 
    cache[amount] = -1;
  else
    cache[amount] = min;
  
  return cache[amount];
};

module.exports = {
  minChange,
};
