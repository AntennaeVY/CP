/**
 * @param {{ hand: 'L' | 'R', color: string }[]} gloves
 * @returns {string[]} Colors of matched pairs
 */
function matchGloves(gloves) {
  // Code here
  const m = {};
  const t = {
    "L": 0,
    "R": 1,
  }

  gloves.forEach(({hand, color}) => {
    m[color] ||= [0, 0];
    m[color][t[hand]] += 1;
  })
  
  return gloves.reduce((acc, {hand, color}) => {
    if (m[color][t[hand]] > 0 && m[color][1 - t[hand]] > 0) {
      m[color][1 - t[hand]] -= 1;
      m[color][t[hand]] -= 1;

      return [...acc, color]
    }

    return acc;
  }, []);
}
