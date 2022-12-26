const bfs = (nodeA, nodeB, adjacencyList, visited = new Set()) => {
   let ans = Infinity;
   const queue = [[nodeA, 0]]; 
  
   while(queue.length > 0) {
     const [node, distance] = queue.shift();
     visited.add(node);
     
     if (node == nodeB)
       return distance;
     
     for (const child of adjacencyList.get(node)) {
        if (visited.has(child))
            continue;
       
        visited.add(child);
        queue.push([child, distance + 1]);
     }

   }
  
   return -1;
}

const shortestPath = (edges, nodeA, nodeB) => {
  const adjacencyList = new Map();

  for (const [a,b] of edges) {
    if (!adjacencyList.has(a))
        adjacencyList.set(a, []);
    
    if (!adjacencyList.has(b))
        adjacencyList.set(b, []);
    
    adjacencyList.set(a, [...adjacencyList.get(a), b]);
    adjacencyList.set(b, [...adjacencyList.get(b), a]);
  }
  
  return bfs(nodeA, nodeB, adjacencyList);
};

module.exports = {
  shortestPath,
};
