
n = 2000
st = ""
char = 'Z'
for i in range (n):
    print(st + char)
    if(char == 'Z'):
        st = st + char
    else:
        char = chr(ord(char) + 1)
    
    print()
