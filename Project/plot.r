dataList = read.csv('Project/simpleGraphListOut.csv')

plot(x = dataList$num_vertices, y = dataList$execution_BFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Tempo de execucao(segundos)",
  main = "Vertices aleatórios - Lista - Num Vértices X Tempo BFS"
)

plot(x = dataList$num_vertices, y = dataList$reached_vertices_BFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Vértices alcançados",
  main = "Vertices aleatórios - Lista - Num Vértices X Vértices alcançados BFS"
)

plot(x = dataList$num_vertices, y = dataList$execution_DFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Tempo de execucao(segundos)",
  main = "Vertices aleatórios - Lista - Num Vértices X Tempo DFS"
)

plot(x = dataList$num_vertices, y = dataList$reached_vertices_DFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Vértices alcançados",
  main = "Vertices aleatórios - Lista - Num Vértices X Vértices alcançados DFS"
)

dataMatriz = read.csv('Project/simpleGraphMatrixOut.csv')

plot(x = dataMatriz$num_vertices, y = dataMatriz$execution_BFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Tempo de execucao(segundos)",
  main = "Vertices aleatórios - Matriz - Num Vértices X Tempo BFS"
)

plot(x = dataMatriz$num_vertices, y = dataMatriz$reached_vertices_BFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Vértices alcançados",
  main = "Vertices aleatórios - Matriz - Num Vértices X Vértices alcançados BFS"
)

plot(x = dataMatriz$num_vertices, y = dataMatriz$execution_DFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Tempo de execucao(segundos)",
  main = "Vertices aleatórios - Matriz - Num Vértices X Tempo DFS"
)

plot(x = dataMatriz$num_vertices, y = dataMatriz$reached_vertices_DFS, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Vértices alcançados",
  main = "Vertices aleatórios - Matriz - Num Vértices X Vértices alcançados DFS"
)


dataListRandomEdges = read.csv('Project/simpleGraphRandomEdgesListOut.csv')
# RANDOM ARESTAS
plot(x = dataListRandomEdges$num_arestas, y = dataListRandomEdges$execution_BFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Tempo de execucao(segundos)",
  main = "Aresta Aleatoria - Lista - Num Arestas X Tempo BFS"
)

plot(x = dataListRandomEdges$num_arestas, y = dataListRandomEdges$reached_vertices_BFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Vértices alcançados",
  main = "Aresta Aleatoria - Lista - Num Arestas X Vértices alcançados BFS"
)

plot(x = dataListRandomEdges$num_arestas, y = dataListRandomEdges$execution_DFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Tempo de execucao(segundos)",
  main = "Aresta Aleatoria - Lista - Num Arestas X Tempo DFS"
)

plot(x = dataListRandomEdges$num_arestas, y = dataListRandomEdges$reached_vertices_DFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Vértices alcançados",
  main = "Aresta Aleatoria - Lista - Num Arestas X Vértices alcançados DFS"
)

dataMatrixRandomEdges = read.csv('Project/simpleGraphRandomEdgesMatrixOut.csv')
# RANDOM ARESTAS
plot(x = dataMatrixRandomEdges$num_arestas, y = dataMatrixRandomEdges$execution_BFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Tempo de execucao(segundos)",
  main = "Aresta Aleatoria - Matriz - Num Arestas X Tempo BFS"
)

plot(x = dataMatrixRandomEdges$num_arestas, y = dataMatrixRandomEdges$reached_vertices_BFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Vértices alcançados",
  main = "Aresta Aleatoria - Matriz - Num Arestas X Vértices alcançados BFS"
)

plot(x = dataMatrixRandomEdges$num_arestas, y = dataMatrixRandomEdges$execution_DFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Tempo de execucao(segundos)",
  main = "Aresta Aleatoria - Matriz - Num Arestas X Tempo DFS"
)

plot(x = dataMatrixRandomEdges$num_arestas, y = dataMatrixRandomEdges$reached_vertices_DFS, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Vértices alcançados",
  main = "Aresta Aleatoria - Matriz - Num Arestas X Vértices alcançados DFS"
)