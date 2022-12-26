const countPaths = (grid, i=0, j=0, cache={}) => {
  if (cache[i]?.[j] !== undefined))
      return cache[i][j];
  
  if (i >= grid.length || j >= grid[0].length || grid[i][j] == 'X')
    return 0;
  
  if (i == grid.length-1 && j == grid[0].length-1)
    return 1;

  if (cache[i] === undefined)
    cache[i] = {};
  
  cache[i][j] = countPaths(grid, i+1, j, cache) + countPaths(grid, i, j+1, cache);
  return cache[i][j];
};

module.exports = {
  countPaths,
};
