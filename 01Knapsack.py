v = [int(_) for _ in input("Values : ").strip().split(" ")]
w = [int(_) for _ in input("Weights : ").strip().split(" ")]
totalW = int(input("Total weight of knapsack : "))

lenV = len(v)

table = [[0 for i in range(totalW+1)] for j in range(lenV + 1)]

for i in range(1,lenV+1,1):  #using dp to fill up the table
	for j in range(1,totalW + 1,1):
		if j - w[i - 1] >= 0:
			table[i][j] = max(table[i - 1][j],v[i - 1] + table[i - 1][j - w[i - 1]])
		else:
			table[i][j] = table[i - 1][j]

finalList = [0 for i in range(len(v))]

i = lenV
j = totalW

while(i >= 1):  #backtracking
	if table[i][j] != table[i - 1][j]:
		finalList[i - 1] = 1
		j -= w[i - 1]
	i -= 1
for i in table:
	print(i)
print(finalList)
"""
for i in table:
	print(i)
	"""