function fixPackages(packages) {
  const regex = /\(([^()]+)\)/;
  let match = packages.match(regex);
  while (match) {
    const reversed = match[1].split('').reverse().join('');
    packages = packages.replace(match[0], reversed);
    match = packages.match(regex);
  }
  return packages;
}
