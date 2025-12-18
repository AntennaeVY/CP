/**
 * @param {string[][]} board
 * @returns {boolean}
 */
function hasFourInARow(board) {
  // hack xd
  if (!board.some(row => row.includes('.'))) return false

  const rows = board.length
  const cols = board[0].length

  for (let y = 0; y < rows; y++) {
    for (let x = 0; x < cols; x++) {
      const color = board[y][x]

      if (!color || color === '.') continue

      const fitRight = x <= cols - 4
      const fitDown  = y <= rows - 4
      const fitLeft  = x >= 3

      if (fitRight) {
        if (color === board[y][x + 1] &&
            color === board[y][x + 2] &&
            color === board[y][x + 3]) return true
      }

      if (!fitDown) continue

      if (color === board[y + 1][x] &&
          color === board[y + 2][x] &&
          color === board[y + 3][x]) return true

      if (fitRight) {
        if (color === board[y + 1][x + 1] &&
            color === board[y + 2][x + 2] &&
            color === board[y + 3][x + 3]) return true
      }

      if (fitLeft) {
        if (color === board[y + 1][x - 1] &&
            color === board[y + 2][x - 2] &&
            color === board[y + 3][x - 3]) return true
      }
    }
  }

  return false
}
