// class Node {
//   constructor(val) {
//     this.val = val;
//     this.left = null;
//     this.right = null;
//   }
// }

const breadthFirstValues = (root) => {
  const queue = [root];
  const nodes = [];
  
  while(queue.length) {
    const front = queue.shift();
    if (!front) continue;
    
    nodes.push(front.val);
    queue.push(front.left, front.right);
  }
  
  return nodes;
};

module.exports = {
  breadthFirstValues,
};
