const maxPathSum = (grid, i=grid.length-1, j=grid[0].length-1, cache={}) => {
  if (cache[i]?.[j] !== undefined)
    return cache[i][j];
  
  if (i==0 && j==0)
    return grid[i][j];
  
  if (cache[i] === undefined)
    cache[i]= {};
  
  if (i==0) {
    cache[i][j] = maxPathSum(grid, i, j-1, cache);
  } else if (j==0) {
    cache[i][j] = maxPathSum(grid, i-1, j, cache);
  } else {
    cache[i][j] = Math.max(maxPathSum(grid, i-1, j, cache), maxPathSum(grid, i, j-1, cache));
  }
  
  cache[i][j] += grid[i][j];
  
  return cache[i][j];
};

module.exports = {
  maxPathSum,
};
