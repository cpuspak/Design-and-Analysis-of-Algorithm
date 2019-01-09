def binarySearch(a,n,first,last):
	if first <= last:
		mid = int((first+last)/2)
		if a[mid] == n:
			return mid
		elif a[mid] > n:
			return binarySearch(a,n,first,mid - 1)
		else:
			return binarySearch(a,n,mid + 1,last)
	else:
	 	return -1 
if __name__ == '__main__':
	a = sorted([int(v) for v in raw_input("Enter space separated integers : ").strip().split(" ")])
	n = int(raw_input("Enter ele to search : "))
	print("sorted array :",a)
	index = binarySearch(a,n,0,len(a) - 1)
	if index == -1:
		print("Not found")
	else:
		print("Element found at index :",index)
