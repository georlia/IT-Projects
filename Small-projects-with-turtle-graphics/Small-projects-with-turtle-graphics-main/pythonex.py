import turtle
from data import letters


# Function to draw a single pixel with a specified size
def draw_pixel(size):
  turtle.pendown()
  turtle.begin_fill()
  turtle.fillcolor('orange')
  turtle.pencolor('black')
  
  # Draw a square to represent the pixel
  for i in range(4):
    turtle.forward(size)
    turtle.right(90)
  
  turtle.end_fill()
  turtle.penup()

# Function to draw a single letter based on the letter's pixel data
def draw_letter(letter, size, spacing):
  turtle.penup()
  row_num = len(letter)
  col_num = len(letter[0])

  # Loop through each row
  for row in range(row_num):
    # Loop through each column
    for col in range(col_num):
      if letter[row][col]:
        draw_pixel(size)

      # Move to the next pixel column
      turtle.forward(size)

    # Reset to the start of the row
    turtle.back(size * col_num)
    turtle.right(90)
    # Move down to the next row
    turtle.forward(size)
    turtle.left(90)

  turtle.forward(size * col_num + spacing)
  turtle.left(90)
  turtle.forward(size * row_num)
  turtle.right(90)

# Function to draw the entire name on the screen
def draw_name(name):
  width = turtle.window_width()
  height = turtle.window_height()
  margin = 10

  # Assuming all letters are of the same size
  cols_per_letter = len(letters[name[0]][0])
  rows_per_letter = len(letters[name[0]])

  # Calculate the pixel size based on the screen dimensions
  size_based_on_width = (width - margin * 2) / (cols_per_letter * len(name) + (len(name) - 1))
  size_based_on_height = (height - margin * 2) / rows_per_letter
  size = min(size_based_on_width, size_based_on_height) # Choose the smaller size

  # Calculate the starting position for drawing the name
  total_name_width = size * cols_per_letter * len(name) + size * (len(name) - 1)

  # Calculate starting position to center the name horizontally
  start_x = -total_name_width / 2

  # Calculate starting position to center the name vertically
  start_y = size * rows_per_letter / 2

  # Move to starting position
  turtle.penup()
  turtle.goto(start_x, start_y)

  # Draw each letter in the name
  for letter in name:
    draw_letter(letters[letter], size, size)

# Function to write an error message on the screen
def write_error_message():
  turtle.color("#ffffff")
  turtle.penup()
  x_pos = -turtle.window_width() // 2 + 10
  y_pos = turtle.window_height() // 2 - 20
  turtle.goto(x_pos, y_pos)
  turtle.write("Oops! We currently only support English letters...", align="left", font=("Arial", 12, "normal"))
  # Move to the next line position
  turtle.penup()
  turtle.goto(x_pos, y_pos - 30)
  turtle.pendown()
  turtle.write("Please rerun and enter an English name 🥲", align="left", font=("Arial", 12, "normal"))
  turtle.penup()

# Function to draw the name if it's valid or display an error message
def draw_name_if_valid(name):
  if name and name.isalpha():
    draw_name(name.lower())
  else:
    write_error_message()
    draw_name("Codebay".lower())

# Main section to set up turtle environment and get user input
turtle.tracer(40) # Speed up the drawing
turtle.ht() # Hide the turtle cursor
name = input("What's your name? (English letters only)")#message in terminal
draw_name_if_valid(name)
turtle.done() # Finish the drawing process
