import turtle
t = turtle.Turtle()
t.speed(10)

def prve():
    t.pencolor("cyan")
    for i in range (5):
        t.fd(100)
        t.lt(72)
        t.dot(5)
def druhe():
    t.pensize(3)
    t.pencolor("yellow")
    for i in range(5):
        t.fd(100)
        t.rt(144)
def tretie():
    t.pencolor("yellow")
    t.dot(20)
    for i in range(20):
        t.pencolor("palegreen")
        t.pu()
        t.fd(15)
        t.pd()
        t.fd(50)
        t.rt(180)
        t.pu()
        t.fd(65)
        t.lt(360/40)
        t.pencolor("maroon")
        t.pu()
        t.fd(15)
        t.pd()
        t.fd(50)
        t.rt(180)
        t.pu()
        t.fd(65)
        t.lt(360/40)
        
