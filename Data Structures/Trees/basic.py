# python program to demonstrate some of the above
# terminologies

# Function to add an edge between vertices x and y

# Function to print the parent of each node


def printParents(node, adj, parent):

	# current node is Root, thus, has no parent
	if (parent == 0):
		print(node, "->Root")
	else:
		print(node, "->", parent)

	# Using DFS
	for cur in adj[node]:
		if (cur != parent):
			printParents(cur, adj, node)

# Function to print the children of each node


def printChildren(Root, adj):

	# Queue for the BFS
	q = []

	# pushing the root
	q.append(Root)

	# visit array to keep track of nodes that have been
	# visited
	vis = [0]*len(adj)

	# BFS
	while (len(q) > 0):
		node = q[0]
		q.pop(0)
		vis[node] = 1
		print(node, "-> ", end=" ")

		for cur in adj[node]:
			if (vis[cur] == 0):
				print(cur, " ", end=" ")
				q.append(cur)
		print("\n")

# Function to print the leaf nodes


def printLeafNodes(Root, adj):

	# Leaf nodes have only one edge and are not the root
	for i in range(0, len(adj)):
		if (len(adj[i]) == 1 and i != Root):
			print(i, end=" ")
	print("\n")

# Function to print the degrees of each node


def printDegrees(Root, adj):

	for i in range(1, len(adj)):
		print(i, ": ", end=" ")

		# Root has no parent, thus, its degree is equal to
		# the edges it is connected to
		if (i == Root):
			print(len(adj[i]))
		else:
			print(len(adj[i])-1)

# Driver code


# Number of nodes
N = 7
Root = 1

# Adjacency list to store the tree
adj = []
for i in range(0, N+1):
	adj.append([])

# Creating the tree
adj[1].append(2)
adj[2].append(1)

adj[1].append(3)
adj[3].append(1)

adj[1].append(4)
adj[4].append(1)

adj[2].append(5)
adj[5].append(2)

adj[2].append(6)
adj[6].append(2)

adj[4].append(7)
adj[7].append(4)

# Printing the parents of each node
print("The parents of each node are:")
printParents(Root, adj, 0)

# Printing the children of each node
print("The children of each node are:")
printChildren(Root, adj)

# Printing the leaf nodes in the tree
print("The leaf nodes of the tree are:")
printLeafNodes(Root, adj)

# Printing the degrees of each node
print("The degrees of each node are:")
printDegrees(Root, adj)

# This code is contributed by rj13to.
