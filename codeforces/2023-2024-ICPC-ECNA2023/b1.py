m,n,k,s = map(int, input().split())
a = [float(x) for x in input().split()]
b = [float(x) for x in input().split()]

arr = a + b
arr = sorted(arr, reverse=False)

l = arr[0]
r = arr[-1]
uniform_step = (r - l) / k


hs = [l + (i-1) * uniform_step + uniform_step / 2 for i in range(1, k+1)]

def sq_dist(x, y):
    return (x - y) * (x - y)
for xx in range(2000):
    group = [[] for i in range(k)]
    j = 0
    for i in range(len(arr)):
        if j < k-1 and  sq_dist(hs[j], arr[i]) < sq_dist(hs[j+1], arr[i]):
            group[j].append(arr[i])
        else: 
            if(j < k - 1):
                j += 1
            group[j].append(arr[i])

    hs = [sum(group[i]) / len(group[i]) for i in range(k)]
    loss = [sum([sq_dist(hs[i], x) for x in group[i]]) for i in range(k)]
    loss = sum(loss)
    loss += (s/2)*(s/2)*(m+n)

    # print(f"step: {xx}, loss: {loss}")
    # print(group)

print(loss)