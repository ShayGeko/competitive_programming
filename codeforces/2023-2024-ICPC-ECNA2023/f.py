
n = int(input())
nums = [int(x) for x in input().split()]


st = []

def push(st, x):
    for i in range(len(st)-1, -1, -1):
        if(st[i] == x):
            # found match and nothing in between is greater than x
            st = st[:i]
            st = push(st, 2*x)
            return st
        if(st[i] > x):
            break
    st.append(x)
    return st
        
    

for i in range(n):
    st = push(st, nums[i])
    # print(nums[i], ": ", st)

maxi = 0
for i in range(len(st)):
    maxi = max(maxi, st[i])
print(maxi)