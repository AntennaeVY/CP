const cache = new Map();

const fib = (n) => {
  if (cache.has(n))
    return cache.get(n);
  
  if (n == 0 || n == 1)
      return n;
  
  cache.set(n, fib(n-1) + fib(n-2));
  return cache.get(n);
};

module.exports = {
  fib,
};
