n=int(input())
k=int(input())
pomocna=n
for i in range(1,k):
    pomocna=pomocna*(n-i)
print(pomocna/k)
