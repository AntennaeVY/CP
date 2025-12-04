/**
 * @param {Array<{ toy: string, quantity: number }>} giftsToProduce
 * @returns {string[]} Array of manufactured gifts
 */
function manufactureGifts(giftsToProduce) {
  return  giftsToProduce
    .filter(g => +g.quantity > 0)
    .map(g => Array.from({length: g.quantity}, () => g.toy))
    .flat()
}
