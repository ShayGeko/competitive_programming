a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";n=int(input());o=" "*(n-1);print(o+'>\n'+o+'|\n'+o+'.')
for i in range(1,n):print(o[:-i]+'/'+a[:i]+(a[i-2::-1]if i>1 else'')+'\\')