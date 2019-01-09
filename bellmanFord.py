def fillMatrix(n,e,temp):
	arr = [[0 for v in range(n)] for u in range(n)]
	for i in temp:
		arr[i[0] - 1][i[1] - 1] = i[2]
	return arr

n = int(input("Enter no of vertices of directed graph : "))
e = int(input("Enter no of connections and their weights : "))
temp = []
for _ in range(e):
	temp.append([int(v) for v in input().strip().split()])
costMatrix = fillMatrix(n,e,temp)

dist = [0]+[10**10 for v in range(n-1)]
flag = 0
for _ in range(n-1):
	if flag == 1:
		break
	else:
		flag = 1
	for i in range(len(costMatrix)):
		for j in range(len(costMatrix)):
			if costMatrix[i][j] != 0:
				if dist[i]+costMatrix[i][j] < dist[j]:
					dist[j] = dist[i]+costMatrix[i][j]
					flag = 0
for i in range(len(dist)):
	if dist[i] >= 10**10:
		dist[i] = "Infinite"
print(dist)
