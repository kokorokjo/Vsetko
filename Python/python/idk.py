from tkinter import *

from PIL import Image

# nacitanie obrazka zo suboru
img = Image.open("/home/martin/Desktop/Programy/Python/python/neviem/zviera0.png")

# vytvorenie okna
root = Tk()
root.title("Zobrazenie obrazka")




# zobrazenie obrazka
img.show()

root.mainloop()
