const maxPalinSubsequence = (str, start=0, end=str.length-1, cache={}) => {
  if (start > end)
      return 0;
  
  if (start == end)
      return 1;
  
  if (cache[start] !== undefined && cache[start][end] !== undefined)
      return cache[start][end];
  
  if (cache[start] === undefined)
    cache[start] = {};
  
  if (str[start] == str[end])
    cache[start][end] = 2 + maxPalinSubsequence(str, start+1, end-1, cache);
  else
    cache[start][end] = Math.max(maxPalinSubsequence(str, start+1, end, cache), maxPalinSubsequence(str, start, end-1, cache));

  return cache[start][end];
};

module.exports = {
  maxPalinSubsequence,
};
