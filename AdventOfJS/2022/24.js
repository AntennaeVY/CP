function canExit(maze) {
  const visited = Array.from(maze, () => Array.from(maze[0], () => false));
  

  const dfs = (i, j) => {
    if (visited[i][j])
      return false;

    if (maze[i][j] == 'S')
      return true;

    visited[i][j] = true;

    let ans = false;

    if (i > 0 && maze[i-1][j] != 'W')    
      ans = ans || dfs(i-1, j);

    if (i < maze.length - 1 && maze[i+1][j] != 'W')
      ans = ans || dfs(i+1, j);

    if (j > 0 && maze[i][j-1] != 'W')
      ans = ans || dfs(i, j-1);

    if (j < maze[i].length - 1 && maze[i][j+1] != 'W')
      ans = ans || dfs(i, j+1);

    return ans;
  }
  
  let result;

  maze.forEach((_, i) => {
    maze[i].forEach((_, j) => {
      if (maze[i][j] == 'E')
        result = dfs(i, j);
    })
  })

  return result;
}
