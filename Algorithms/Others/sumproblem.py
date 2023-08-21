def isSubsetSum(set, n, sum):
     
    subset =([[False for i in range(sum + 1)]
            for i in range(n + 1)])
     

    for i in range(n + 1):
        subset[i][0] = True
 
    for i in range(1, sum + 1):
         subset[0][i]= False
             
    
    for i in range(1, n + 1):
        for j in range(1, sum + 1):
            if j<set[i-1]:
                subset[i][j] = subset[i-1][j]
            if j>= set[i-1]:
                subset[i][j] = (subset[i-1][j] or
                                subset[i - 1][j-set[i-1]])
     
   
    for i in range(n + 1):
        # print(i,end=" ")
        for j in range(sum + 1):
            print (i,j,":",subset[i][j], end =" ")
        print()
    return subset[n][sum]
         

set = [3, 34, 4, 12, 5, 2]
sum = 9
n = len(set)
if (isSubsetSum(set, n, sum) == True):
        print("True")
else:
        print("False")