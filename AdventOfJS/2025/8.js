/**
 * @param {string} toy - The toy to find the first unique one letter
 * @returns {string} The first unique letter in the toy
 */
function findUniqueToy(toy) {
  const count = {};
  const chars = Array.from(toy);

  for (const c of chars) {
    count[c.toLowerCase()] ||= 0; 
    count[c.toLowerCase()] += 1;
  }

  let ans = "";

  for (const c of chars) {
    if (count[c.toLowerCase()] == 1) {
      ans = c;
      break;
    }
  }

  return ans;
}
