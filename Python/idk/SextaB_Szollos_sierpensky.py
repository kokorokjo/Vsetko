import tkinter
c= tkinter.Canvas(width=800, height=800, bg="black")
c.pack()

def triangle(x1, y1, x2, y2, x3, y3, color):
    c.create_polygon(x1, y1, x2, y2, x3, y3, outline="white")

def sierpinski(x1, y1, x2, y2, x3, y3, n):
    if n == 0:
        return
    else:
        triangle(x1, y1, x2, y2, x3, y3, "white")
        sierpinski(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2, n-1)
        sierpinski(x2, y2, (x1+x2)/2, (y1+y2)/2,  (x2+x3)/2, (y2+y3)/2, n-1)
        sierpinski(x3, y3, (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2 , n-1)

sierpinski(100, 100, 700, 100, 400, 700, 8)




tkinter.mainloop()