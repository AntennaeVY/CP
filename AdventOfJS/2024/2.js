function createFrame(names) {
  const x = Math.max(...names.map(n => n.length))

  let ans = "*".repeat(x + 4) + '\n';

  names.forEach((name) => {
    ans += ("* " + name.padEnd(x, ' ') + ' *') + '\n';
  })

  ans += "*".repeat(x + 4);

  return ans;
}
