from turtle import *
pu()
setpos(0,0)
pd()
zoz=[0,0,100,0,100,100,0,100]
n=len(zoz)-1
for i in range(0,n,2):
    setpos(zoz[i],zoz[i+1])
setpos(zoz[0],zoz[1])