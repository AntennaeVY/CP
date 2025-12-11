/**
 * @param {string[]} warehouse - Array of strings representing the grid
 * @returns {number} - Count of unsafe gifts
 */
function findUnsafeGifts(warehouse) {
  let count = 0
  const h = warehouse.length
  const w = warehouse[0].length

  for (let y = 0; y < h; y++) {
    for (let x = 0; x < w; x++) {
      if (warehouse[y][x] !== '*') continue

      const isSafe = 
        warehouse[y]?.[x + 1] === '#' || // Right
        warehouse[y]?.[x - 1] === '#' || // Left
        warehouse[y + 1]?.[x] === '#' || // Down
        warehouse[y - 1]?.[x] === '#'    // Up

      if (!isSafe) count++
    }
  }

  return count
}
