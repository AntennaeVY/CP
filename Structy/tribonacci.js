const cache = new Map();

const tribonacci = (n) => {
  if (cache.has(n))
    return cache.get(n);
  
  if (n <= 2)
      return Math.max(0, n-1);
  
  cache.set(n, tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3));
  return cache.get(n);
};

module.exports = {
  tribonacci,
};

