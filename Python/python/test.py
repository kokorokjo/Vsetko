import tkinter as tk
import random
from PIL import Image


SIRKA = 800
VYSKA = 600
POCET_ZVIERAT = 5
POCET_STOP = 3
PREDMET_ZMENY = 50

root = tk.Tk()
root.geometry(f"{SIRKA}x{VYSKA}")
root.title("Hra na určovanie stôp")

zvierata = []
stopy = []
for i in range(POCET_ZVIERAT):
    zviera = tk.PhotoImage(f"/home/martin/Desktop/Programy/Python/python/neviem/zviera{i}.png")
    stopa = tk.PhotoImage(f"/home/martin/Desktop/Programy/Python/python/neviem/stopy{i}.png")
    zvierata.append(zviera)
    stopy.append(stopa)


canvas = tk.Canvas(root, width=SIRKA, height=VYSKA - 100)
canvas.pack(side=tk.TOP)


x_pozicie = []
y_pozicie = []
zviera_cislo = random.randint(0, POCET_ZVIERAT-1)
stopy_zvierata = stopy[zviera_cislo]
for i in range(POCET_STOP):
    x = random.randint(0, SIRKA - 50)
    y = random.randint(0, VYSKA - 150)
    canvas.create_image(x, y, anchor=tk.NW, image=stopy_zvierata)
    x_pozicie.append(x)
    y_pozicie.append(y)


for i in range(POCET_ZVIERAT):
    zviera = zvierata[i]
    x = i * 150
    y = 0
    canvas.create_image(x, y, anchor=tk.NW, image=zviera)


def pohyb_zvierata(x, y, krok, zviera_cislo):
    zviera = zvierata[zviera_cislo]
    canvas.move(zviera_id, krok, 0)
    x += krok
    if x >= SIRKA:
        x = -50
        canvas.delete(zviera_id)
        zviera_id = canvas.create_image(x, y, anchor=tk.NW, image=zviera)
    return x

def kontrola_kliku(event):
    x, y = event.x, event.y
    for i in range(POCET_STOP):
        if abs(x - x_pozicie[i]) < PREDMET_ZMENY and abs(y - y_pozicie[i]) < PREDMET_ZMENY:
            canvas.create_image(x_pozicie[i], y_pozicie[i], anchor=tk.NW, image=zvierata[zviera_cislo])


