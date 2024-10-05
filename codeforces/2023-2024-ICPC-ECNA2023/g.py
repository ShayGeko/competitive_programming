import sys
 
#input functions
readint = lambda: int(sys.stdin.readline())
readints = lambda: map(int,sys.stdin.readline().split())
readar = lambda: list(map(int,sys.stdin.readline().split()))
flush = lambda: sys.stdout.flush()
readin = lambda: sys.stdin.readline()[:-1]
readins = lambda: map(str,sys.stdin.readline().split())
 
def binsearch(ar,a,b): # count values between a and b in sorted ar
 
    n = len(ar)
    li,ri = -1,-1
 
    # left endpoint
    low = 0
    high = n-1
    while high-low > 1:
        mid = (low+high)//2
        if ar[mid] >= a: high = mid
        else: low = mid
    if ar[low] >= a: li = low
    elif ar[high] >= a: li = high
    else: li = high+1
 
    # right endpoint
    low = 0
    high = n-1
    while high-low > 1:
        mid = (low+high)//2
        if ar[mid] <= b: low = mid
        else: high = mid
    if ar[high] <= b: ri = high
    elif ar[low] <= b: ri = low
    else: ri = low-1
    return max(0,ri-li+1)


arr = [0, 0, 1,1,1,1,1,1, 2]
print(arr)
print(binsearch(arr, 0, 1))
exit(0)
 
t,s,rd = readints()
trees = {}
ohno = {}
for _ in range(t):
    a,b = readints()
    trees[(a,b)] = 1
    if ohno.get(b) == None: ohno[b] = list()
    ohno[b].append(a)
#print(ohno)
for ii in ohno.keys():
    ohno[ii].sort()
ar = list()
for _ in range(s):
    a,b = readints()
    ar.append((a,b))
 
# get initial guess points
u = list()
d = list()
l = list()
r = list()
a,b = ar[0][0],ar[0][1]
for i in trees.keys():
    x,y = i[0],i[1]
    if trees.get((x-a,y-b)) == None: u.append((x-a,y-b))
    if trees.get((x-b,y+a)) == None: r.append((x-b,y+a))
    if trees.get((x+a,y+b)) == None: d.append((x+a,y+b))
    if trees.get((x+b,y-a)) == None: l.append((x+b,y-a))
 
 
# for each direction, compute viable cases
ans = list()
for z in u:
    x,y = z[0],z[1]
    flag = True
    for a in ar:
        if trees.get((x+a[0],y+a[1])) == None:
            flag = False
            break
    if flag:
        tc = 0
        for snth in range(y-rd,y+rd+1):
            if ohno.get(snth) != None:
                diff = rd-abs(snth-y)
                tc += binsearch(ohno[snth],x-diff,x+diff)
        if tc == s: ans.append((x,y))
for z in r:
    x,y = z[0],z[1]
    flag = True
    for a in ar:
        if trees.get((x+a[1],y-a[0])) == None:
            flag = False
            break
    if flag:
        tc = 0
        for snth in range(y-rd,y+rd+1):
            if ohno.get(snth) != None:
                diff = rd-abs(snth-y)
                tc += binsearch(ohno[snth],x-diff,x+diff)
        if tc == s: ans.append((x,y))
for z in d:
    x,y = z[0],z[1]
    flag = True
    for a in ar:
        if trees.get((x-a[0],y-a[1])) == None:
            flag = False
            break
    if flag:
        tc = 0
        for snth in range(y-rd,y+rd+1):
            if ohno.get(snth) != None:
                diff = rd-abs(snth-y)
                tc += binsearch(ohno[snth],x-diff,x+diff)
        if tc == s: ans.append((x,y))
for z in l:
    x,y = z[0],z[1]
    flag = True
    for a in ar:
        if trees.get((x-a[1],y+a[0])) == None:
            flag = False
            break
    if flag:
        tc = 0
        for snth in range(y-rd,y+rd+1):
            if ohno.get(snth) != None:
                diff = rd-abs(snth-y)
                tc += binsearch(ohno[snth],x-diff,x+diff)
        if tc == s: ans.append((x,y))
ans = list(set(ans))
if len(ans) == 0: print("Impossible")
elif len(ans) == 1: print(ans[0][0],ans[0][1])
else: print("Ambiguous")