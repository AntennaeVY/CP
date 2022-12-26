// class Node {
//   constructor(val) {
//     this.val = val;
//     this.left = null;
//     this.right = null;
//   }
// }

const treeMinValue = (root) => {
  if (!root) return Infinity;
  
  return Math.min(root.val, treeMinValue(root.left), treeMinValue(root.right))
};

module.exports = {
  treeMinValue,
};
