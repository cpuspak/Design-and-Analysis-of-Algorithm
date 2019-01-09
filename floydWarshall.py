class Graph:           			#class Graph 
	def __init__(self,edges,n):
		self.edges = edges      # no of edges
		self.costMatrix = [[10**9 for i in range(n)] for j in range(n)]    #initialisation of cost atrix
		self.vertices = n     				# no of vertices of graph
		self.generateCostMatrix()			#generation of cost matrix from information of edges and weights

	def generateCostMatrix(self):           #generation of cost matrix
		for i in edges:
			self.costMatrix[i[0] - 1][i[1] - 1] = i[2]

		for i in range(self.vertices):
			self.costMatrix[i][i] = 0     #as no sealf loops present in graph

	def floydWarshall(self):                #floyd warshall algorithm
		for k in range(self.vertices):
			temp = self.costMatrix
			for i in range(self.vertices):
				for j in range(self.vertices):
					if i != j:
						temp[i][j] = min([temp[i][j],self.costMatrix[i][k]+self.costMatrix[k][j]]) #updating the cost matrix 
			self.costMatrix = temp																   #based on relaxation

		return self.costMatrix


print("Enter no of vertices : ")
n = int(input())
print("Enter no of edges : ")
e = int(input())

print("Enter edges : ")

edges = []

for i in range(e):
	edges.append([int(v) for v in input().strip().split()])   #entering edges
															  #edges is a matrix of dimention 'e X 3' denoting two vertices
															  #connected and their weight
g = Graph(edges,n)

finalMatrix = g.floydWarshall()
for i in finalMatrix:
	print(i)