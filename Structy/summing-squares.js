const summingSquares = (n, cache = {}) => {
  if (cache[n])
    return cache[n];
  
  if (n==0)
    return 0;
  
  let ans = Infinity;
  
  for(let i=1; i*i <= n; i++) {
    if (n-i*i < 0)
      continue;
    
    ans = Math.min(ans, 1 + summingSquares(n-i*i, cache));
  }
  
  cache[n] = ans;
  return ans;
};

module.exports = {
  summingSquares,
};
