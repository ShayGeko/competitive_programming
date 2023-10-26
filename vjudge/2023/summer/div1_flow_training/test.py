from random import *
n = 1000



for xxx in range(20):
    print(n)
    cnt = 0
    for i in range(5):
        for j in range(n):
            k = randint(0, 1)
            if (j == 0 and ((cnt < 3 and k == 1) or 3 - cnt > 4 - i)) :
                print('@', end='')
                cnt+=1
            print(randint(0, 9), end='')
        print()
    assert cnt == 3
print(0)
