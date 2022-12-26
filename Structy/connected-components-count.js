const dfs = (root, graph, visited) => {
  if (visited.has(root))
      return;
  
  visited.add(root);
  
  for (const node of graph[root]) {
    if (visited.has(node))
        continue;
    
    dfs(String(node), graph, visited);
  }
}

const connectedComponentsCount = (graph) => {
    const visited = new Set();
    let count = 0;
    
    for (const node in graph) {
       if (visited.has(node))
          continue;
      
       dfs(node, graph, visited);
       console.log(visited);
       count += 1;
    }
    
    return count;
};



module.exports = {
  connectedComponentsCount,
};
