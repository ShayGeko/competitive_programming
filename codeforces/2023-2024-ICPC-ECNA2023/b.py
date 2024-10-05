m,n,k,s = map(int, input().split())
a = [float(x) for x in input().split()]
b = [float(x) for x in input().split()]

arr = a + b
arr = sorted(arr, reverse=False)

inf = 1e9
N = n + m
dp = [[inf for _ in range(N)] for j in range(k+1)]
pref = [0 for i in range(N+1)]
pref_sq = [0 for i in range(N+1)]
for i in range(N):
    pref[i+1] = pref[i] + arr[i]
    pref_sq[i+1] = pref_sq[i] + arr[i]*arr[i]

## (x-  x_i)^2 = k*x^2 + sum(x_i^2) - 2x * sum(x_i)

## row 0

for i in range(N):
    x = pref[i+1] / (i+1)
    f = (i+1)*x*x + pref_sq[i+1] - 2*x * pref[i+1]
    dp[0][i] = f

arr1 = [pref[i+1] / (i+1) for i in range(N)]
print(arr)
print(arr1)
print(dp[0])

for i in range(1,k):
    for j in range(N):
        ## go over 0 -> j for breaking point
        for xx in range(1, j):
            f_l = dp[i-1][xx]

            # r = (xx .. j]
            r_sum = pref[j+1] - pref[xx]
            kk = j - (xx) +1
            x = (r_sum) / (kk)

            xi_sq = (pref_sq[j+1] - pref_sq[xx]) / (kk)
            ## sum (x-  x_i)^2 = k*x^2 + sum(x_i^2) - 2x * sum(x_i)
            f_r = kk * x*x + xi_sq - 2 * x * (r_sum)

            print(f"{i}-{j}-{xx}: kk {kk} x {x} sum xi^2 {xi_sq} sum xi {r_sum} ||| f_l {f_l} f_r {f_r}")

            if(f_r < 0): exit(0)

            dp[i][j] = min(dp[i][j], f_l + f_r)


print("--------------------")
for i in range(k):
    print(dp[i])

print(dp[k-1][N-1])





