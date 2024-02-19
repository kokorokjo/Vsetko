from math import factorial
n = int(input())
a = [0] * n
idk = [int(i) for i in input().split()]
for i in range(n-1):
    a[idk[i]-1]+=1
koniec= n
for i in a:
    koniec *= factorial(i+1)
koniec //=a[0]+1
print(koniec%1000000007)