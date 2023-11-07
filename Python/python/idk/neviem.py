import turtle
t = turtle.Turtle()
#neviem ci tam mas toto ale aj toto tam musis mat
def daco():
    a=int(input("daco"))
    #zabudla si dat int
    if a==1:
        #a tu tu chyba T
        t.fd(100)
        t.rt(90)
        t.fd(100)
        t.rt(90)
        t.fd(100)
        t.rt(90)
        t.fd(100)
    elif a==2:
        t.fd (20)
    else:
        t.fd (20)
        t.rt(90)
        t.fd(20)
