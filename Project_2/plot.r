dataList = read.csv('Project_2/digraphList.csv')

plot(x = dataList$num_vertices, y = dataList$execution_time, 
type = "l",
  xlab = "Num Vértices",
  ylab = "Tempo de execucao(segundos)",
  main = "Vertices aleatórios - Lista - Num Vértices X Tempo"
)

plot(x = dataList$num_arestas, y = dataList$execution_time, 
type = "l",
  xlab = "Num Arestas",
  ylab = "Tempo de execucao(segundos)",
  main = "Vertices aleatórios - Lista - Num Arestas X Tempo"
)
