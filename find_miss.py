lst = [-1] + range(1, 5) + range(6, 51) 
def find_missing(array, start, end) :
	if start < end :
		mid = (start + end) / 2
		temp = end - start
		if temp <= 1 :
			return array[end] - 1
		
		#if array[mid] - array[start] == (mid - start) :
		#array[mid] should be equal to mid + 1
		#if it is then that means all the values from start to mid are not missing
		#then make start = mid and then search the right sub-array
		#otherwise search the left sub-array
		if array[mid] == mid :
			start = mid
		else :
			end = mid
		print array[start:end]
		return find_missing(array, start, end)
print "[%d...%d]"%(lst[0], lst[len(lst) - 1])
print find_missing(lst, 0, len(lst) - 1)