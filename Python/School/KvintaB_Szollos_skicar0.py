import tkinter as tk
canvas = tk.Canvas(width=2000,height=2000, bg='white')
canvas.pack()

posledne_x=0
posledne_y=0
color_pen = 'black'
width_pen = 3
idk=20+20

red_id=canvas.create_rectangle(10,10,30,30, fill='red')
green_id=canvas.create_rectangle(10,40,30,60, fill='green')
blue_id=canvas.create_rectangle(10,70,30,90, fill='blue')
black_id=canvas.create_rectangle(10,100,30,120, fill='black')
width_1=canvas.create_rectangle(10,95+idk,30,100+idk, fill='black')
width_2=canvas.create_rectangle(10,105+idk,30,115+idk, fill='black')
width_3=canvas.create_rectangle(10,120+idk,30,135+idk, fill='black')

def save(event):
    global posledne_x, posledne_y
    posledne_x=event.x
    posledne_y=event.y

def red(event):
    global color_pen
    color_pen='red'
def green(event):
    global color_pen
    color_pen='green'
def blue(event):
    global color_pen
    color_pen='blue'
def black(event):
    global color_pen
    color_pen='black'
def width1(event):
    global width_pen
    width_pen=1
def width2(event):
    global width_pen
    width_pen=3
def width3(event):
    global width_pen
    width_pen=6

def kreslenie(event):
    global posledne_x, posledne_y
    canvas.create_line(posledne_x, posledne_y, event.x, event.y, fill=color_pen, width=width_pen)
    save(event)

canvas.tag_bind(red_id, '<Button-1>',red)
canvas.tag_bind(green_id, '<Button-1>',green)
canvas.tag_bind(blue_id, '<Button-1>',blue)
canvas.tag_bind(black_id, '<Button-1>',black)
canvas.tag_bind(width_1, '<Button-1>',width1)
canvas.tag_bind(width_2, '<Button-1>',width2)
canvas.tag_bind(width_3, '<Button-1>',width3)

canvas.bind("<Button-1>", save)
canvas.bind("<B1-Motion>", kreslenie)
canvas.mainloop()