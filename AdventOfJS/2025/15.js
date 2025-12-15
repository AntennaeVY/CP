/**
 * @param {Array<Object>} data
 * @param {string} sortBy
 * @returns {string}
 */
function drawTable(data, sortBy) {
  const sortedData = [...data].sort((a, b) => {
    if (a[sortBy] > b[sortBy]) return 1
    if (a[sortBy] < b[sortBy]) return -1
    return 0
  })

  const keys = Object.keys(data[0])

  const widths = keys.map((key, index) => {
    const headerLen = 1
    const maxContent = Math.max(...data.map(d => String(d[key]).length))
    return Math.max(headerLen, maxContent)
  })

  const drawRow = (items) => {
    const cells = items.map((item, i) => ` ${String(item).padEnd(widths[i])} `)
    return `|${cells.join('|')}|`
  }

  const separator = `+${widths.map(w => '-'.repeat(w + 2)).join('+')}+`

  const headers = keys.map((_, i) => String.fromCharCode(65 + i))
  
  return [
    separator,
    drawRow(headers),
    separator,
    ...sortedData.map(row => drawRow(keys.map(k => row[k]))),
    separator
  ].join('\n')
}
