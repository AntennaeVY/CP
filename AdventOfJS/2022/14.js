function getOptimalPath(path) {
  const solve = (path, i, j) => {
    if (i == path.length - 1)
      return path[i][j];

    return path[i][j] + Math.min(solve(path, i + 1, j), solve(path, i + 1, j + 1));
  }

  return solve(path, 0, 0);
}
