/**
 * @param {string[]} gifts - The array of gifts to filter
 * @returns {string[]} An array with the unique filtered gifts
 */
function filterGifts(gifts) {
  // Code here
  return gifts.filter(g => !g.includes("#"));
}

