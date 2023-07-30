const hasPath = (adjacencyList, nodeA, nodeB, visited = new Map()) => {
  if (nodeA == nodeB)
      return true;
  
  let found = false;
  visited.set(nodeA, true);
  
  for (const node of adjacencyList.get(nodeA)) {
    if (visited.has(node))
      continue;
    
    found ||= hasPath(adjacencyList, node, nodeB, visited);
  }
  
  return found;
};

const undirectedPath = (edges, nodeA, nodeB) => {
  const adjacencyList = new Map();
  
  for(const [from, to] of edges) {
    if (!adjacencyList.has(from))
        adjacencyList.set(from, []);
    
    if (!adjacencyList.has(to))
        adjacencyList.set(to, []);
    
    adjacencyList.set(from, [...adjacencyList.get(from), to]);
    adjacencyList.set(to, [...adjacencyList.get(to), from]);
  }
  
  return hasPath(adjacencyList, nodeA, nodeB);
};

module.exports = {
  undirectedPath,
};
