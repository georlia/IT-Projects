import turtle
import colorsys

# Setup the screen
screen = turtle.Screen()
screen.bgcolor("black")  # Black background makes colors pop!
t = turtle.Turtle()
t.speed(0) # Fastest speed

# Create a colorful flower
colors = ["#1AFF00", "#FB0086", "#EAFB04", "#FF945F","#552BFD"] # Cute pinks and purples

for i in range(36):
    t.color(colors[i % 5]) # Cycles through our cute colors
    t.circle(100)          # Draws a petal
    t.left(10)             # Rotates slightly for the next petal

t.hideturtle()
screen.exitonclick()
