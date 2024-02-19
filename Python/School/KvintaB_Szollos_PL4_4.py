import turtle
t = turtle.Turtle()
t.speed(10)
def prve():
    t.pencolor("orange")
    t.pensize(5)
    for i in range(9):
        t.fd(40)
        t.lt(180)
        t.fd(40)
        t.lt(140)

    t.dot(40, "yellow")
def druhe():
    for i in range(10):
        t.pencolor("red")
        t.fd(20)
        t.lt(90)
        t.fd(20)
        t.rt(90)
def tretie():
    t.pencolor("green")
    for i in range(4):
        t.fd(20)
        t.lt(90)
        t.fd(20)
        t.lt(90)
        t.fd(20)
        t.rt(90)
def stvrte():
    t.pencolor("red")
    for i in range(10):
        t.dot(10)
        t.rt(36)
        t.fd(10)
def piate():
    t.lt(90)
    for i in range(3):
        t.fd(20)
        t.rt(120)
        t.fd(20)
        t.rt(180)
        t.fd(20)
        t.lt(60)
        t.fd(20)
        t.rt(180)
        t.fd(20)
        t.rt(300)
def sieste():
    t.pencolor("green")
    t.lt(90)
    for i in range(6):
        t.fd(20)
        t.rt(90)
        t.fd(20)
        t.rt(90)
        t.fd(20)
        t.lt(90)
        t.fd(20)
        t.lt(90)
