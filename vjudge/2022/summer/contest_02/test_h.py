import random;
n = 3000
k = 200000
maxim = 1e9
arr = []
for i in range (0, n):
    arr.append(random.randint(1, maxim))
print(n);
for i in range (0, n):
    print(arr[i])

print(k);
for i in range (0, k):
    l = random.randint(1, n)
    r = random.randint(l, n)
    z = random.randint(1, maxim)
    print (l, r, z)

