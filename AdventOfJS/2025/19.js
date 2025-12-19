/**
 * @param {string[][]} routes
 * @returns {string[]}
 */
function revealSantaRoute(routes) {
  // 1. Extraemos el inicio y el primer destino del primer tramo
  // Se nos garantiza que el índice 0 es el inicio.
  const [start, next] = routes[0]
  
  // 2. Inicializamos la ruta con estos dos puntos
  const route = [start, next]
  let currentDest = next

  // 3. Creamos un Mapa para búsquedas rápidas (O(1))
  // Clave: Origen -> Valor: Destino
  const connections = new Map()
  for (const [from, to] of routes) {
    connections.set(from, to)
  }

  // 4. Recorremos la cadena
  // Mientras el destino actual sea el origen de otro vuelo...
  while (connections.has(currentDest)) {
    const nextStop = connections.get(currentDest)
    route.push(nextStop)
    currentDest = nextStop
  }

  return route
}
