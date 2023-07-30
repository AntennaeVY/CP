const isPrime = (n) => {
  if (n==1 || n==0) return false;
  
  if (n < 0) n = -n;
  
  for(let i=2; i*i <= n; i++) {
    if (n%i == 0) return false;
  }
  
  return true;
};

module.exports = {
  isPrime,
};
