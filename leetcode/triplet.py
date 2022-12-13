def triplet(arr):
    ci = 0;
    count = 0
    for i in range(0,len(arr)):
        ci = 0
        for j in range(0,len(arr)):
            if(arr[j]>arr[ci] and j>ci):
                ci = j
            print(arr[ci],arr[j])
    return count
    
print(triplet([1,2,3,4]))
# (1,2,3) (1,3,4) (2,3,4) (1,2,4)