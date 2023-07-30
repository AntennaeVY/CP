const dfs = (i, j, grid, visited) => {
  if (grid[i][j] == 'W' || visited[i][j])
     return;
  
  visited[i][j] = true;
  
  if (i > 0)
    dfs(i-1, j, grid, visited);
  
  if (i < grid.length - 1)
    dfs(i+1, j, grid, visited);
  
  if (j > 0)
    dfs(i, j-1, grid, visited);
  
  if (j < grid[0].length - 1) 
    dfs(i, j+1, grid, visited);
}

const islandCount = (grid) => {
  let ans = 0;
  const visited = Array.from(Array(grid.length), () => Array.from(Array(grid[0].length), () => false));
  
  for (let i=0; i < grid.length; i++) {
    for(let j=0; j < grid[i].length; j++) {
      if (visited[i][j] || grid[i][j] == 'W')
        continue;
      
      dfs(i, j, grid, visited);
      ans += 1;
    }
  }
  
  return ans;
};

module.exports = {
  islandCount,
};
