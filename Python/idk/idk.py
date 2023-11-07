import random

n=int(input("Zadaj pocet hodov: "))
a=0
def stastie(n,a):
    for i in range(n):
        k=random.randint(1,6)
        if (k == 6):
            a=a+1
    print(a/n)
stastie(n,a)

