/**
 * @param {object} tree1 - The first binary tree
 * @param {object} tree2 - The second binary tree
 * @returns {[boolean, string]}
 */
function isTreesSynchronized(tree1, tree2) {
  const areMirrors = (node1, node2) => {
 
    if (!node1 && !node2) return true

  
    if (!node1 || !node2 || node1.value !== node2.value) return false

 
    return areMirrors(node1.left, node2.right) && 
           areMirrors(node1.right, node2.left)
  }

  return [areMirrors(tree1, tree2), tree1.value]
}
