class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.data = key 
def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.data:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root
def inOrderTraversal(root): 
    if root: 
        inOrderTraversal(root.left) 
        print(root.val) 
        inOrderTraversal(root.right) 
root = None
keys = list(map(int, input().split(" ")))
for key in keys:
    root = insert(root, key)
print(inOrderTraversal(root))
