import tkinter as tk
my_w = tk.Tk()
width,height=410,210 # set the variables 
c_width,c_height=width-10,height-45 # canvas width height
d=str(width)+"x"+str(height) # window dimensions 
my_w.geometry(d) # window height and width 

c1 = tk.Canvas(my_w, width=c_width, height=c_height,bg='lightgreen')
c1.grid(row=1,column=0,padx=5,pady=5)

step=5 # value of each incremental movement, change this 
x1,y1=5,int(c_height/2) # left top coordinate of rectangle 
x2,y2=x1+15,y1+15      # right bottom cooridnate of rectangle  
r1=c1.create_rectangle(x1, y1, x2,y2,fill='red')  # draw rectangle 

def my_move(event):    
    c1.move(r1,step,step) # increase x and y both, move right-down
    
b1=tk.Button(my_w,text='Move',command=lambda:my_move('x'))
b1.grid(row=2,column=0)
my_w.mainloop()