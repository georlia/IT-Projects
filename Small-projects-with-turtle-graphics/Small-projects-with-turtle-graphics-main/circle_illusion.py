import turtle
import colorsys

t = turtle.Turtle()
t.speed(0)
turtle.bgcolor("black")

# This creates a rainbow spirograph
for i in range(180):
    # Generates a new color for every single circle
    color = colorsys.hsv_to_rgb(i/180, 1, 1)
    t.pencolor(color)
    
    t.circle(100)
    t.left(2) # The tiny turn creates the "overlap" effect

turtle.done()
