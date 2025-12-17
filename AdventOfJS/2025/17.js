/**
 * @param {string[][]} board
 * @returns {boolean}
 */
function hasFourLights(board) {
  const rows = board.length
  const cols = board[0].length

  for (let y = 0; y < rows; y++) {
    for (let x = 0; x < cols; x++) {
      const color = board[y][x]
      
      if (color === '.') continue

      if (
        board[y][x + 1] === color &&
        board[y][x + 2] === color &&
        board[y][x + 3] === color
      ) return true

      if (
        board[y + 1]?.[x] === color &&
        board[y + 2]?.[x] === color &&
        board[y + 3]?.[x] === color
      ) return true
    }
  }

  return false
}
