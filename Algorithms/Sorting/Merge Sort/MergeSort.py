
def mergeSort(array):
    if len(array) > 1:
        r = len(array)//2
        L = array[:r]
        M = array[r:]
        
        # Sort the two halves
        mergeSort(L)
        mergeSort(M)

        i = j = k = 0


        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = M[j]
                j += 1
            k += 1


        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1
        print("split",L,"-",M)



array = [6, 5, 12, 10, 9, 1,78,65,45,67,34,45,23,33]
print("before Sorting:",array)
mergeSort(array)
print("Sorted array is: ",array)
print("Time Complexity is nlogn")
