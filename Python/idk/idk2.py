import tkinter as tk
import random

root = tk.Tk()
root.title("Line of Squares")

canvas = tk.Canvas(root, width=4000, height=1000)
canvas.pack()



def rad(x,y):
   for i in range(20):
     canvas.create_rectangle(x, y, x + 15, y + 15, fill="gray")
     x += 15 + random.randint(12, 20)
x = 0
y = 0
for i in range(20):
    rad(0,y+20*i)




root.mainloop()
