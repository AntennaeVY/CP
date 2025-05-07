/**
 * @param {number[]} indices - The reno indices
 * @param {number} length - The length of the race
 * @returns {string} The reno race
 */
function drawRace(indices, length) {
  const n = indices.length

  const can = indices.map((i) => i != 0);
  const pos = indices
    .map((i) => (i + length) % length)
  const lanes = pos
    .map((_, i) => `${'~'.repeat(length)} /${i+1}`)
  const reinders = lanes.map((str, i) => {
      const j = pos[i]
      return str.substring(0, j) + 
      '~r'[+can[i]] + 
      str.substring(j+1)
  })
  const isometric = reinders.map((str, i) => {
     return ' '.repeat(n - i - 1) + 
     str
  })

  return isometric
  .reduce((p, c) => p + c + '\n', "")
  .slice(0, -1)
}
