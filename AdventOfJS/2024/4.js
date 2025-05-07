function createXmasTree(height, ornament) {
  const maxWitdh = 2*height - 1;

  let tree = "";

  for(let i=1; i <= maxWitdh; i+=2) {
    tree += "_".repeat((maxWitdh - i) / 2);
    tree += ornament.repeat(i);
    tree += "_".repeat((maxWitdh - i) / 2);
    tree += "\n";
  }

  tree += "_".repeat((maxWitdh - 1) / 2) + "#" + "_".repeat((maxWitdh - 1) / 2) + "\n";
  tree += "_".repeat((maxWitdh - 1) / 2) + "#" + "_".repeat((maxWitdh - 1) / 2);

  return tree;
}
