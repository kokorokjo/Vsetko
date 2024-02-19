import turtle
import random

def slnko(n,strana,luc):
    turtle.up()
    x=random.randint(-350,300)
    y=random.randint(100,220)
    turtle.goto(x,y)
    angle = 180 - 180*(n-2)/n

    for i in range(n):
        turtle.down()
        obdlznik(strana,luc)

        turtle.left(angle)



def obdlznik(a,b):
    turtle.down()

    turtle.forward(a)
    turtle.right(90)
    turtle.forward(b)
    turtle.right(90)
    turtle.forward(a)
    turtle.right(90)
    turtle.forward(b)
    turtle.right(90)
    turtle.forward(a)
n=random.randint(5,15)
strana=random.randint(10,20)
luc=random.randint(30,80)
slnko(n,strana,luc)

turtle.done()
