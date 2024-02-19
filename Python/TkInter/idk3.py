import tkinter
import random

t=tkinter.Canvas(width=500,height=500)

def cislokruhu(event):
    random_cislo=random.randint(0,100)
    farby=["red","green","blue","yellow","pink","orange","purple","black","white"]
    random_farba=random.choice(farby)
    while random_farba=="black":
        random_farba=random.choice(farby)
    t.create_oval(event.x-10,event.y-10,event.x+10,event.y+10,fill=random_farba)
    t.create_text(event.x,event.y,text=random_cislo,fill="black")

t.bind("<Button-1>",cislokruhu)
t.pack()
t.mainloop()
