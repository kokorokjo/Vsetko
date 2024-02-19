# import tkinter

# # create canavas
# canvas = tkinter.Canvas(width=400, height=400)
# canvas.pack()
# def neviem(nieco):
#     print("neviem")
# canvas.bind('<KeyPress-Left>',neviem)

# canvas.mainloop()

import tkinter

canvas = tkinter.Canvas()
canvas.pack()

def klik(parameter):
    print('klik')

canvas.bind('<Button-1>', klik)
# bind for left arrow
canvas.bind('<KeyPress-a>', klik)
def test_vlavo(event):
    print('sipka vlavo')

def test_a(event):
    print('stlacil si klaves a')

canvas.bind_all('a', test_a)
canvas.bind_all('<Left>', test_vlavo)

canvas.mainloop()