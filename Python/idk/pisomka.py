# python 3.8
vypis = print

def f(x):
    if x == 0:
        return 1

    g = lambda x: f(x-2)
    h = lambda x: g(x+1)
    return (h(x)+h(x)) % 47

n = int(input())

for _____ in range(1,n+1):
    candy = 0
    for ______ in range(1,n+1):
        if ______ % (len( ([]) ) + len( [()] ) ):
            candy = n
            break
        elif ______ == n and _____ % (  len( ([]) ) + len( ([],[])) ):
            break
        elif _____ % ______ == 0:
            candy = candy + int(chr(49)+chr(48),2)
    else: continue

    if candy & 1:
        res = f(n-_____)
        print(res)
    elif candy and 2 == 2 and (candy | 3 == candy + 3):
        pass
    else:
        vypis(_____)

# look at my code, my code is amazing