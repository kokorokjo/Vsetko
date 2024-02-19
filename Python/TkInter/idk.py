import tkinter as tk
my_w = tk.Tk()
width,height=410,230 # set the variables 
c_width,c_height=width-15,height-75 # canvas width height
d=str(width)+"x"+str(height)
my_w.geometry(d) 
c1 = tk.Canvas(my_w, width=c_width, height=c_height,bg='lightgreen')
c1.grid(row=0,column=0,columnspan=3,padx=5,pady=2)

step=5 # value of each incremental movement, change this 
x1,y1=5,int(c_height/2) # starting position 
x2,y2=x1+15,y1+15      # starting position 
r1=c1.create_rectangle(x1, y1, x2,y2,fill='red')  # draw rectangle 

def my_left(event):    
    c1.move(r1,-step,0) # Move Left direction without any up or down movement
def my_right(event):
    c1.move(r1,step,0) # Move right 
def my_up(event):
    c1.move(r1,0,-step) # Move up
def my_down(event):
    c1.move(r1,0,step) # Move down
        
b1=tk.Button(my_w,text='Up',font=18,bg='yellow',command=lambda:my_up('x'))
b1.grid(row=1,column=1,padx=2,pady=2,sticky='ew')
b2=tk.Button(my_w,text='Left',font=18,bg='yellow',command=lambda:my_left('x'))
b2.grid(row=2,column=0,padx=2,pady=2,sticky='ew')
b3=tk.Button(my_w,text='Down',font=18,bg='yellow',command=lambda:my_down('x'))
b3.grid(row=2,column=1,padx=2,pady=2,sticky='ew')
b4=tk.Button(my_w,text='Right',font=18,bg='yellow',command=lambda:my_right('x'))
b4.grid(row=2,column=2,padx=2,pady=2,sticky='ew')

my_w.mainloop()