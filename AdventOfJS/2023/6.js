function maxDistance(movements) {
  const type = {
    "<": 0,
    ">": 0,
    "*": 0
  }

  for (const move of movements) {
    type[move] += 1;
  }

  const allLeft = Math.abs(type['<'] + type['*'] - type['>']);
  const allRight = Math.abs(type['>'] + type['*'] - type['<']);

  return Math.max(allLeft, allRight);
}
