/**
 * @param {string[][]} maze
 * @returns {boolean}
 */
function canEscape(maze) {
  const grid = maze.map(row => [...row])

  const startRow = grid.findIndex(r => r.includes('S'))
  const startCol = grid[startRow].indexOf('S')

  const stack = [[startRow, startCol]]

  while (stack.length > 0) {
    const [y, x] = stack.pop()

    const cell = grid[y]?.[x]

    if (cell === 'E') return true

    if (!cell || cell === '#') continue

    grid[y][x] = '#'

    stack.push(
      [y + 1, x], // Abajo
      [y - 1, x], // Arriba
      [y, x + 1], // Derecha
      [y, x - 1]  // Izquierda
    )
  }

  return false
}
