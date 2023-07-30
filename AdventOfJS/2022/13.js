function getFilesToBackup(lastBackup, changes) {
  return [...new Set(changes
    .filter(([, change]) => change > lastBackup)
    .map(([id,]) => id)
    .sort((a, b) => a - b))];
}
