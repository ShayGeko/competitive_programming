import random
import string


text_size = 5001
k = text_size

while k > 0:
    r = random.randint(1, max(200,k))
    print(''.join(random.choices(string.ascii_letters,k=r)))
    k-=r