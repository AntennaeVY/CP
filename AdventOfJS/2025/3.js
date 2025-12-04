/**
 * @param {number} size - The size of the gift
 * @param {string} symbol - The symbol to draw
 * @returns {string} The gift drawn
 */
function drawGift(size, symbol) {
  if (size < 2)
    return "";

  const x = Array.from({length: size-1})
    .reduce((acc, _) => [...acc, symbol + " ".repeat(size-2) + symbol], [])

  x[0] = symbol.repeat(size);
  x[size-1] = symbol.repeat(size);

  return x.join("\n");
}
