// class Node {
//   constructor(val) {
//     this.val = val;
//     this.left = null;
//     this.right = null;
//   }
// }

const treeSum = (root) => {
  if (!root) return 0;
  
  let sum = root.val;
  
  sum += treeSum(root.left);
  sum += treeSum(root.right);
  
  return sum;
};

module.exports = {
  treeSum,
};
