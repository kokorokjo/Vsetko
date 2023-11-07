from microbit import *
import radio

number=0
kanal=42
radio.on()
radio.config(channel=kanal)
message=''
while True:
    message=radio.receive()
    if button_a.is_pressed() or message=="A":
        if message!="A":radio.send("A")
        message = ""
        if number==2**25:
            continue
        display.clear()
        number+=1
        bin_number= bin(number)
        bin_number= bin_number[2:]
        for i,j in enumerate(reversed(bin_number)):
           display.set_pixel(i%5, i//5, 9 if j=="1" else 0)
        sleep(100)
    if button_b.is_pressed() or message=="B":
        if message!="B":radio.send("B")
        message = ""
        if number==0:
            continue
        display.clear()
        number-=1
        bin_number= bin(number)
        bin_number= bin_number[2:]
        for i,j in enumerate(reversed(bin_number)):
           display.set_pixel(i%5, i//5, 9 if j=="1" else 0)
        sleep(100)