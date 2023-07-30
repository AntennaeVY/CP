const sumPossible = (amount, numbers, cache = {}) => {
  if (amount === 0)
    return true;
  
  if (amount < 0)
    return false;
  
  if (cache[amount] !== undefined)
    return cache[amount];

  for(const num of numbers) {
    if (sumPossible(amount-num, numbers, cache)) {
      cache[amount-num] = true;
      return true;
    }
  }
  
  cache[amount] = false;
  return false;
};

module.exports = {
  sumPossible,
};
