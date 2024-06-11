import sys

#input functions
readint = lambda: int(sys.stdin.readline())
readints = lambda: map(int,sys.stdin.readline().split())
readar = lambda: list(map(int,sys.stdin.readline().split()))
flush = lambda: sys.stdout.flush()

"""
TODO: Include the seg tree template used here in the Python
library code
"""



# base function for creating the seg tree
def create_tree(ar):
    n = len(ar)
    
    # generate base setup
    basear = list()
    for i in range(n):
        basear.append([1,ar[i]])
    seg = list()
    seg.append(basear)
    while len(seg[-1]) != 1: # must create new layer
        layer = list()
        for ii in range(len(seg[-1])//2):
            layer.append(seg_func(seg[-1][2*ii],seg[-1][2*ii+1]))
        seg.append(layer)
    return seg

# seg tree function for determining parent value based on the children
def seg_func(ar,br,m=1000000007):
    na,nb = len(ar),len(br)
    cr = [0]*min((na+nb-1),101)
    n = len(cr)
    for a in range(na):
        for b in range(min(nb,n-a)):
            cr[a+b] += ar[a]*br[b]
    for c in range(n):
        cr[c] = cr[c] % m
    return cr

# compute the query based on the subtrees in the segtree
def query(seg,l,r,k):
    ans = [1] # store result here
    li,ri = l,r
    for i in range(len(seg)):
        if li > ri: break
        if li % 2 == 1: # use left side segment
            ans = seg_func(ans,seg[i][li])
            li += 1
        if ri % 2 == 0: # use right side segment
            ans = seg_func(ans,seg[i][ri])
            ri -= 1
        li //= 2
        ri //= 2
    return ans[k]

# updates segment tree from leaf to parents
def update(seg,index,val):
    i = index
    seg[0][i] = val
    for ii in range(1,len(seg)):
        i //= 2
        if i == len(seg[ii]): break # no parent
        seg[ii][i] = seg_func(seg[ii-1][i*2],seg[ii-1][i*2+1])
        

n,c,t = readints()
ar = list()
for _ in range(n):
    a,b = readints()
    ar.append(b-a+1)
sar = create_tree(ar)
for _ in range(t):
    q = readar()
    if q[0] == 0: print(query(sar,q[1]-1,q[2]-1,q[3]))
    else: update(sar,q[1]-1,[1,q[3]-q[2]+1])
