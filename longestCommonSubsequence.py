print("Enter 1st string(All caps) : ")

s1 = input().upper()      #enter 1st string and convert it to caps if it is not already in caps

print("Enter 2nd string(All caps) : ")

s2 = input().upper()	  #enter 2nd string and convert it to caps if it is not already in caps

matrix = [[0 for i in range(len(s1) + 1)] for j in range(len(s2) + 1)] #initialising matrix with all zeros

for i in range(1,len(s2)+1):       #applying dp to solve the problem and finding longest common su
	for j in range(1,len(s1)+1):
		if s1[j - 1] != s2[i - 1]:
			matrix[i][j] = max([matrix[i - 1][j],matrix[i][j - 1]])
		else:
			matrix[i][j] = 1 + matrix[i - 1][j - 1]

arrSubSeq = []

i = len(s2)
j = len(s1)

while(i != 0 and j != 0):     #backtracking our solution
	if matrix[i][j] == matrix[i][j - 1]:
		j -= 1
	elif matrix[i][j] == matrix[i - 1][j]:
		i -= 1
	else:
		arrSubSeq.append(s1[j - 1])
		i -= 1
		j -= 1

print(arrSubSeq[::-1])   #printing the array in rev order as we formed it from last index
