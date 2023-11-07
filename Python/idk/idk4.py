def vypis(n):
    if(n==1):
        print("1")
    else:
        vypis(n-1)
        print(n)
    return
        
def test(n):
    print (n)
    if n>1:
        test(n-1)
    print (-n)


from turtle import *
wn = Screen()

speed(1)

def strom(n):
    if n==0:
        forward(10)
        backward(10)
    else:
        forward(10)
        left(30)
        strom(n-1)
        right(60)
        strom(n-1)
        left(30)
        backward(10)
left(90)
strom(3)
wn.exitonclick()
