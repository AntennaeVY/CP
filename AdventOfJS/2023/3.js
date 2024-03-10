function findNaughtyStep(original, modified) {
  const n = original.length, m = modified.length;

  for(let i=0; i < Math.max(n, m); i++) {
    if (original[i] != modified[i])
      return m > n ? modified[i] : original[i];
  }

  return '';
}
