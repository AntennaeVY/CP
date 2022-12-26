const hasPath = (graph, src, dst, vis = new Map()) => {
  if (src == dst) return true;
  vis.set(src, true);
  
  let found = false;
  
  for (const node of graph[src]) {
    if (vis.has(node)) continue;
    
    found |= hasPath(graph, node, dst, vis);
  }
  
  return !!found;
};

module.exports = {
  hasPath,
};
