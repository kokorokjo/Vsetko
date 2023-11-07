import tkinter 


canvas = tkinter.Canvas()
canvas.pack()


class character():
    x = 10
    y = 10
    color = "red"
    neviem = canvas.create_oval(x, y, x + 40, y + 40, fill=color)

def moveup(e):
    canvas.move(character.neviem, 0,-10 )
  
def moveright(e):
    canvas.move(character.neviem, 10, 0)
    
def movedown(e):
   canvas.move(character.neviem, 0, 10)
   
def moveleft(e):
    canvas.move(character.neviem, -10, 0)
    
    
def test_vlavo(event):
    print('sipka vlavo')
canvas.bind_all('<Left>', test_vlavo)


canvas.bind_all("<Left>", moveleft)
canvas.bind_all("<Right>", moveright)
canvas.bind_all("<Up>", moveup)
canvas.bind_all("<Down>", movedown)

canvas.mainloop()