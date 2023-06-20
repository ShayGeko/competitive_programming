def blabla():
    return 0

fact = [1]*100
for i in range(1, 100):
    fact[i] = fact[i-1]*i

class Node:
    def __init__(self, value:int) -> None:
        self.val = value
        self.left = None
        self.right = None
        self.node_count = 1
        self.ways = 1

def insert(curnode, x:int):
    curnode.node_count += 1
    if(x < curnode.val):
        if(curnode.left is None):
            curnode.left = Node(x)
        else: insert(curnode.left, x)
    else:
        if(curnode.right is None):
            curnode.right = Node(x)
        else: insert(curnode.right, x)
def choose(n: int, k:int):
    return fact[n] // (fact[k]*fact[n-k])

def getNodeCount(node):
    if(node is None): return 0
    return node.node_count

def countWays(node):
    if(node is None): return 1
    lnc = getNodeCount(node.left)
    rnc = getNodeCount(node.right)

    lwc = countWays(node.left)
    rwc = countWays(node.right)

    result = choose(lnc + rnc, lnc) * lwc * rwc
    return result

while(True):
    n = int(input())
    if(n==0): break
    nums = [int(x) for x in input().split()]

    root = Node(nums[0])
    for x in nums[1:]: 
        insert(root, x)
    print(countWays(root))

