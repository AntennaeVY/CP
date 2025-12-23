/**
 * @param {string[][]} map
 * @returns {number}
 */
function minStepsToDeliver(map) {
  const rows = map.length
  const cols = map[0].length
  const size = rows * cols
  
  const visited = new Int8Array(size)
  
  let startRow = 0
  let startCol = 0
  let totalGifts = 0
  
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      const cell = map[r][c]
      if (cell === 'S') {
        startRow = r
        startCol = c
      } else if (cell === 'G') {
        totalGifts++
      }
    }
  }

  if (totalGifts === 0) return 0

  let queue = [[startRow, startCol]]
  visited[startRow * cols + startCol] = 1 

  let steps = 0 
  let totalSteps = 0  
  let foundGifts = 0 
  
  const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]

  while (queue.length > 0) {
    steps++ 
    const nextQueue = [] 

    for (const [r, c] of queue) {
      for (const [dr, dc] of dirs) {
        const nr = r + dr
        const nc = c + dc

        const isInside = nr >= 0 && nr < rows && nc >= 0 && nc < cols
        
        if (isInside) {
          const flatIndex = nr * cols + nc

          if (visited[flatIndex] === 0 && map[nr][nc] !== '#') {
            visited[flatIndex] = 1 
            if (map[nr][nc] === 'G') {
              totalSteps += steps
              foundGifts++
              
              if (foundGifts === totalGifts) return totalSteps
            }

            nextQueue.push([nr, nc])
          }
        }
      }
    }
    
    queue = nextQueue
  }

  return -1
}
