INITIAL_CAPACITY = 7

# Node data structure - essentially a LinkedList node
class Node:
	def __init__(self, key, value):
		self.key = key
		self.value = value
		self.next = None
	def __str__(self):
		return "<Node: (%s, %s), next: %s>" % (self.key, self.value, self.next != None)
	def __repr__(self):
		return str(self)
# Hash table with separate chaining
class HashTable:
    def setUp(self):
        self.ht = HashTable()  
	# Initialize hash table
    def __init__(self):
	    self.capacity = INITIAL_CAPACITY
	    self.size = 0
	    self.buckets = [None]*self.capacity
	# Generate a hash for a given key
	# Input:  key - string
	# Output: Index from 0 to self.capacity
    def hash(self, key):
	    valoare = key%7
	    return valoare

	# Insert a key,value pair to the hashtable
	# Input:  key - string
	# 		  value - anything
	# Output: void
    def insert(self, key, value):
		# 1. Increment size
	    self.size += 1
		# 2. Compute index of key
	    index = self.hash(key)
		# Go to the node corresponding to the hash
	    node = self.buckets[index]
		# 3. If bucket is empty:
	    if node is None:
			# Create node, add it, return
		    self.buckets[index] = Node(key, value)
		    return
		# 4. Iterate to the end of the linked list at provided index
	    prev = node
	    while node is not None:
		    prev = node
		    node = node.next
		# Add a new node at the end of the list with provided key/value
	    prev.next = Node(key, value)

	# Find a data value based on key
	# Input:  key - string
	# Output: value stored under "key" or None if not found
    def find(self, key):
		# 1. Compute hash
	    index = self.hash(key)
		# 2. Go to first node in list at bucket
	    node = self.buckets[index]
		# 3. Traverse the linked list at this node
	    while node is not None and node.key != key:
	    	node = node.next
		# 4. Now, node is the requested key/value pair or None
	    if node is None:
			# Not found
	    	return None
	    else:
			# Found - return the data value
		    return node.value
        
    def test(self):
        vector=[59, 32, 35, 74, 16, 25]
        for i in range(1,6): 
            self.ht.insert(vector[i],vector[i])
        for i in range(1,6): 
            val1=self.ht.find(vector[i])
            print(val1)
	# Remove node stored at key
	# Input:  key - string
	# Output: removed data value or None if not found
    
    
	




    