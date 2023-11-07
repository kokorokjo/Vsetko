# Python program to user input pattern
# using Turtle Programming
import turtle #Outside_In
import turtle
import time
import random

print ("This program draws shapes based on the number you enter in a uniform pattern.")
num_str = input("Enter the side number of the shape you want to draw: ")
if num_str.isdigit():
	squares = int(num_str)

angle = 180 - 180*(squares-2)/squares

turtle.up

x = 0
y = 0
turtle.setpos(x, y)


numshapes = 2
for x in range(numshapes):
	turtle.color(random.random(), random.random(), random.random())
	turtle.up()
	x += 50
	y += 50
	turtle.forward(x)
	turtle.left(y)
	turtle.down()
	turtle.begin_fill()
	for i in range(squares):
		
		turtle.down()
		turtle.forward(40)
		turtle.left(angle)
		turtle.forward(40)
		print (turtle.pos())
		turtle.up()
	turtle.end_fill()


turtle.done()
