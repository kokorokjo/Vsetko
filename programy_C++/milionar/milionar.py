import tkinter as tk
window=tk.Tk()
def odpoved_a():
    global spravne, poradie
    if zoz[poradie][5]=='A':
        spravne=tk.Label(text='Správne')
        spravne.place(x=0,y=0)
        
    else:
        spravne=tk.Label(text=f'Nesprávne\nsprávne odpoveď je: {zoz[poradie][5]}\nSkóre:{vyhry[poradie]}')
        spravne.place(x=0,y=0)

    poradie+=1
def odpoved_b():
    global spravne, poradie
    if zoz[poradie][5]=='B':
        spravne=tk.Label(text='Správne')
        spravne.place(x=0,y=0)
        
    else:
        spravne=tk.Label(text=f'Nesprávne\nsprávne odpoveď je: {zoz[poradie][5]}\nSkóre:{vyhry[poradie]}')
        spravne.place(x=0,y=0)

    poradie+=1
def odpoved_c():
    global spravne, poradie
    if zoz[poradie][5]=='C':
        spravne=tk.Label(text='Správne')
        spravne.place(x=0,y=0)
        
    else:
        spravne=tk.Label(text=f'Nesprávne\nsprávne odpoveď je: {zoz[poradie][5]}\nSkóre:{vyhry[poradie]}')
        spravne.place(x=0,y=0)

    poradie+=1
def odpoved_d():
    global spravne, poradie
    if zoz[poradie][5]=='D':
        spravne=tk.Label(text='Správne')
        spravne.place(x=0,y=0)
        
    else:
        spravne=tk.Label(text=f'Nesprávne\nsprávne odpoveď je: {zoz[poradie][5]}\nSkóre:{vyhry[poradie]}')
        spravne.place(x=0,y=0)

    poradie+=1
def dalej():
    print('funguje')
    global frame, spravne
    frame.destroy()
    spravne.destroy()
    frame=tk.Frame()
    print('funguje2')
    otazka=tk.Label(master=frame,text=zoz[poradie][0])
    odpoved_A=tk.Button(master=frame,text=zoz[poradie][1],command=odpoved_a)
    odpoved_B=tk.Button(master=frame,text=zoz[poradie][2],command=odpoved_b)
    odpoved_C=tk.Button(master=frame,text=zoz[poradie][3],command=odpoved_c)
    odpoved_D=tk.Button(master=frame,text=zoz[poradie][4],command=odpoved_d)
    frame.pack()
    print('nefunguje')

frame=tk.Frame()
spravne=tk.Label()
poradie=0
vyhry=[100,200,300,500,1000,2000,4000,8000,16000,32000,64000,125000,250000,500000,1000000]
subor=open('konecne.txt','r',encoding='UTF-8')
zoz=[]
for i in range(15):
    zoz.append(subor.readline().split('_'))

t_dalej=tk.Button(text='Ďalej',command=dalej)
t_dalej.pack(side='right')
window.mainloop()

