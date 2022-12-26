function fixLetter(letter) {
  return letter
  .replace(/(\s+)/g, ' ')
  .replace(/([?!.,])\1*/g, '$1')
  .replace(/([?!,])\s*\.$/, '$1')
  .replace(/\s*([?!.,])\s*/g, '$1 ')
  .replace(/santa claus/gi, 'Santa Claus')
  .replace(/([?.!]\s[a-z])/g, a => a.toUpperCase())
  .replace(/(^\s)|(\s$)/g, '')
  .replace(/([A-z])$/g, '$1.')
  .replace(/^([a-z])/g, a => a.toUpperCase())
}
