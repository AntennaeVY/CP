const dfs = (root, graph, visited) => {
  if (visited.has(root))
    return 0;
  
  visited.add(root);
  let count = 1;
  
  for (const node of graph[root]) {
    count += dfs(String(node), graph, visited);
  }
  
  return count;
}

const largestComponent = (graph) => {
   const visited = new Set();
   let ans = 0;
  
   for(const node in graph) {
     if (visited.has(node))
        continue;
     
     ans = Math.max(ans, dfs(node, graph, visited));
   }
  
   return ans;
};

module.exports = {
  largestComponent,
};
