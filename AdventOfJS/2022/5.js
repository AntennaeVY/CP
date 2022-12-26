function getMaxGifts(giftsCities, maxGifts, maxCities) {
  return solve(giftsCities, maxGifts, maxCities);
}

solve = (a, s, n, i=0, cnt=0, amt=0) => {
  if (amt == n || i == a.length)
    return cnt;
  
  if (cnt + a[i] <= s)
    return Math.max(solve(a, s, n, i+1, cnt+a[i], amt+1), solve(a,s,n,i+1,cnt,amt));

  return solve(a,s,n,i+1,cnt,amt);
}
