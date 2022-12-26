const dfs = (i, j, grid, visited) => {
  if (grid[i][j] == 'W' || visited[i][j])
     return 0;

  let size = 1;
  visited[i][j] = true;
  
  if (i > 0)
    size += dfs(i-1, j, grid, visited);
  
  if (i < grid.length - 1)
    size += dfs(i+1, j, grid, visited);
  
  if (j > 0)
    size += dfs(i, j-1, grid, visited);
  
  if (j < grid[0].length - 1) 
    size += dfs(i, j+1, grid, visited);
  
  return size;
}

const minimumIsland = (grid) => {
  let ans = Infinity;
  const visited = Array.from(Array(grid.length), () => Array.from(Array(grid[0].length), () => false));
  
  for (let i=0; i < grid.length; i++) {
    for(let j=0; j < grid[i].length; j++) {
      if (visited[i][j] || grid[i][j] == 'W')
        continue;
      
      ans = Math.min(ans, dfs(i, j, grid, visited));
    }
  }
  
  return ans;
};

module.exports = {
  minimumIsland,
};
