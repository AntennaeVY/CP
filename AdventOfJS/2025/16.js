/**
 * @param {number[]} gifts - The gifts to pack
 * @param {number} maxWeight - The maximum weight of the sleigh
 * @returns {number | null}
 */
function packGifts(gifts, maxWeight) {
  if (!gifts.length) return 0

  let sleighs = 1
  let currentWeight = 0

  for (const gift of gifts) {
    if (gift > maxWeight) return null

    currentWeight += gift

    if (currentWeight > maxWeight) {
      sleighs++
      currentWeight = gift
    }
  }

  return sleighs
}
