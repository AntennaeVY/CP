/** @param {number} height - Height of the tree
 *  @param {string} ornament - Character to use as ornament
 *  @param {number} frequency - How often ornaments appear
 *  @returns {string} The decorated tree
 */
function drawTree(height, ornament, frequency) {
  const tree = [];
  let cnt = 1;

  for(let i=1; i <= height; i++) {
    let row = "";
    
    for(let j=1; j <= 2*i - 1; j++) {
      row += (cnt % frequency ? '*' : ornament);
      cnt += 1;
    }

    tree.push(row.padStart(height-i + 2*i-1));
  }

  tree.push("#".padStart(height));

  return tree.join("\n");
}

