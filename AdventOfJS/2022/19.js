function sortToys(toys, positions) {
  return toys
  .map((_, i) => i)
  .sort((a, b) => positions[a] - positions[b])
  .map(v => toys[v]);
}
