function inBox(box) {
  const regex = /^#\s*\*\s*#$/
  return box.slice(1, -1).some((line) => regex.test(line))
}
