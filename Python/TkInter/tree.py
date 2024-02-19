import tkinter
from math import *

c= tkinter.Canvas(width=800, height=800, bg="black")
c.pack()

def kresli(x,y,lengh,angle,depth=0):
    if depth > 10:
        return
    else:
        vx,vy = x+lengh*cos(angle),y+lengh*sin(angle)

        color = 255-depth*25
        hex = f"#{color:02x}{color:02x}{color:02x}"

        c.create_line(x,y,vx,vy,fill=hex,width=10-depth)

        kresli(vx,vy,lengh*0.8,angle-pi/8,depth-1)
        kresli(vx,vy,lengh*0.8,angle-pi/8,depth-1)


kresli(300,550,100,-pi/2)




tkinter.mainloop()