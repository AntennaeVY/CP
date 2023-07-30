class Node {
  constructor(val) {
    this.val = val;
    this.left = null;
    this.right = null;
  }
}

const depthFirstValues = (root) => {
  const children = [];
  if (!root) return children;
  
  children.push(root.val);
  children.push(...depthFirstValues(root.left));
  children.push(...depthFirstValues(root.right));
  
  return children;
};

module.exports = {
  depthFirstValues,
};
