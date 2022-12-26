// class Node {
//   constructor(val) {
//     this.val = val;
//     this.left = null;
//     this.right = null;
//   }
// }

const maxPathSum = (root) => {
  if (root === null) return -Infinity;
  if (root.left === null && root.right === null) return root.val;
  
  return root.val + Math.max(maxPathSum(root.left), maxPathSum(root.right));
};

module.exports = {
  maxPathSum,
};
