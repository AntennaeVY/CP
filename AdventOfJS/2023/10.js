function createChristmasTree(ornaments, height) {
  let tree = "", index = 0;

  for(let j=0; j < height; j++) {
    let row = "";

    tree += " ".repeat(height - j - 1);

    for(let _=0; _ <= j; _++, index++) {
      row += ornaments[index % ornaments.length] + " ";
    }

    tree += row.trimEnd() + '\n';
  }

  tree += " ".repeat(height - 1) + "|\n";

  return tree;
}
