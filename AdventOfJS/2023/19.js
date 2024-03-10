function revealSabotage(store) {
  const d = [
    [-1, -1],
    [-1, +0],
    [-1, +1],
    [+0, +1],
    [+1, +1],
    [+1, +0],
    [+1, -1],
    [+0, -1]
  ]

  const ans = store;
  const n = ans.length, m = ans[0].length;

  for(let i=0; i < n; i++) {
    for(let j=0; j < m; j++) {
      if (ans[i][j] == '*')
        continue;

      for(const [y, x] of d) {
        if (i+y < 0 || i+y >= n || j+x < 0 || j+x >= m) 
          continue;

        if (ans[i+y][j+x] == '*') {
          const c  = ans[i][j];

          ans[i][j] = c == ' ' ? '1' : (+c + 1).toString();
        }
      }
    }
  }

  return ans;
}
