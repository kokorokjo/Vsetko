from tkinter import *
from tkinter.ttk import *

canvas = Canvas(master = None)
rectangle = canvas.create_rectangle(5, 5, 25, 25, fill = "black")
canvas.pack()
x=1
y=0
def movement():
    canvas.move(rectangle, x, y)
    canvas.after(100, movement())

def left():
    global x, y
    x = -1
    y = 0
def right():
    global x, y
    x = 1
    y = 0
def up():
    global x, y
    x = 0
    y = -1
def down():
    global x, y
    x = 0
    y = 1

master = Tk()

# Tk().bind("<KeyPress-left>", lambda: left())
# Tk().bind("<KeyPress-right>", lambda: right())
# Tk().bind("<KeyPress-up>", lambda: up())
# Tk().bind("<KeyPress-down>", lambda: down())

master.bind("<KeyPress-Left>", lambda e: left(e))
master.bind("<KeyPress-Right>", lambda e: right(e))
master.bind("<KeyPress-Up>", lambda e: up(e))
master.bind("<KeyPress-Down>", lambda e: down(e))

mainloop()