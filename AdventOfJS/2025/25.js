/**
 * @param {string} code
 * @returns {number}
 */
function execute(code) {
  let value = 0
  const len = code.length
  
  const jumps = new Int16Array(len)
  const stack = []

  for (let i = 0; i < len; i++) {
    const char = code[i]
    if (char === '[' || char === '{') {
      stack.push(i)
    } else if (char === ']' || char === '}') {
      const open = stack.pop()
      jumps[open] = i
      jumps[i] = open
    }
  }

  for (let ip = 0; ip < len; ip++) {
    const char = code[ip]

    if (char === '+') value++
    else if (char === '-') value--
    else if (char === '[') {
      if (value === 0) ip = jumps[ip]
    } 
    else if (char === ']') {
      if (value !== 0) ip = jumps[ip]
    } 
    else if (char === '{') {
      if (value === 0) ip = jumps[ip]
    }
  }

  return value
}/**
 * @param {string} code
 * @returns {number}
 */
function execute(code) {
  let value = 0
  const len = code.length
  
  const jumps = new Int16Array(len)
  const stack = []

  for (let i = 0; i < len; i++) {
    const char = code[i]
    if (char === '[' || char === '{') {
      stack.push(i)
    } else if (char === ']' || char === '}') {
      const open = stack.pop()
      jumps[open] = i
      jumps[i] = open
    }
  }

  for (let ip = 0; ip < len; ip++) {
    const char = code[ip]

    if (char === '+') value++
    else if (char === '-') value--
    else if (char === '[') {
      if (value === 0) ip = jumps[ip]
    } 
    else if (char === ']') {
      if (value !== 0) ip = jumps[ip]
    } 
    else if (char === '{') {
      if (value === 0) ip = jumps[ip]
    }
  }

  return value
}
