/**
 * @param {string} board - Represent the board situation
 * @param {string} moves - Movement direction
 * @returns {'fail' | 'crash' | 'success'}
 */
function moveReno(board, moves) {
  const grid = board.trim().split('\n')
  
  let row = grid.findIndex(r => r.includes('@'))
  let col = grid[row].indexOf('@')

  const steps = {
    'L': [0, -1],
    'R': [0, 1],
    'U': [-1, 0],
    'D': [1, 0]
  }

  for (const move of moves) {
    const [dRow, dCol] = steps[move]

    row += dRow
    col += dCol

    const cell = grid[row]?.[col]

    if (cell === '*') return 'success'
    if (!cell || cell === '#') return 'crash'
  }

  return 'fail'
}
