import tkinter
import math

c= tkinter.Canvas(width=800, height=800, bg="black")
c.pack()

def ciara(x1,y1,x2,y2,depth=0):
    if depth > 6:
        return
    c.create_line(x1,y1,x2,y2,fill="white")
    prvy_x,prvy_y = x1+(x2-x1)*1/3,y1+(y2-y1)*1/3
    druhy_x,druhy_y = x1+(x2-x1)*2/3,y1+(y2-y1)*2/3
    c.create_triangle(prvy_x,prvy_y,druhy_x,druhy_y,depth+1)
    c.create_triangle(prvy_x,prvy_y,druhy_x,druhy_y,depth+1)

ciara(200,300,400,400)

tkinter.mainloop()