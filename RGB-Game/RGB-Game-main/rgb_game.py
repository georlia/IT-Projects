from tkinter import *
import tkinter as tk
from random import randrange
from tkinter import messagebox

def randomcolor():
    global a, b, c
    a = randrange(256)
    b = randrange(256)
    c = randrange(256)
    print(a, b, c)
    return "#%02x%02x%02x" % (a, b, c)

def col(value):
    finalcolour = "#%02x%02x%02x" % (s1.get(), s2.get(), s3.get())
    right_frame.config(bg=finalcolour)


def find_distance():
    global r, g, bl, distance, tries
    r = int(s1.get())
    g = int(s2.get())
    bl = int(s3.get())

    distance = ((a - r) ** 2 + (b - g) ** 2 + (c - bl) ** 2) ** 0.5
    return abs(distance)


def check_distance():
    distance = find_distance()
    global kokkino, prasino, mple
    selection1 = str(s1.get())
    selection2 = str(s2.get())
    selection3 = str(s3.get())
    cm = selection1 + "," + selection2 + "," + selection3
    global tries
    label = Label(master)
    label.config(text=cm)
    label.pack(side=BOTTOM)
    apost = 25
    tries = tries + 1
    trylabel=Label(master,text=f"Attempt{tries}/5", font=("Helvetica bold", 30))
    trylabel.place(relx=0.0,rely=1.0,anchor="sw")
    master.attributes("-topmost",True)
    if distance <= apost and tries <= 5:
        win = Tk()
        win.geometry("600x350")
        Label(win, text="ΣΥΓΧΑΡΗΤΗΡΙΑ ΤΟ ΒΡΗΚΕΣ!!! ", font=("Helvetica bold", 15)).pack(
            pady=20
        )
        win.attributes("-topmost", True)
        win.after(1000, lambda: win.destroy())  
        win.after(1000, lambda: master.destroy())
        print(tries)
        win.mainloop()

    elif distance > apost and tries <= 5:
        win = Tk()
        win.geometry("600x350")
        x = Label(win, text="ΛΑΘΟΣ! ", font=("Helvetica bold", 15))
        x.pack(pady=20)
        win.attributes("-topmost", True)
        win.after(
            1100, lambda: win.destroy()
        )  
        win.after(1100, lambda: master.destroy())
        print(tries)
        win.mainloop()

    elif tries >= 5:
        win = Tk()
        win.geometry("600x350")
        x = Label(win, text="ΠΟΛΛΕΣ ΠΡΟΣΠΑΘΕΙΕΣ ", font=("Helvetica bold", 15))
        x.pack(pady=20)
        win.attributes("-topmost", True)
        win.after(
            1100, lambda: win.destroy()
        )  
        win.after(1100, lambda: master.destroy())
        print(tries)
        win.mainloop()


tries = 0
master = Tk()
master.geometry("1000x1000")

l2 = Label(master, text="Συνδυασμός βασικών χρωμάτων ")
l2.pack()
top_frame = Frame(master, width=700, height=500)
top_frame.pack(side=TOP)

right_frame = Frame(master, width=700, height=500)
right_frame.pack(side=RIGHT)

s1 = Scale(
    top_frame, from_=0, to=255, bg="red", orient=HORIZONTAL, length=200, command=col
)
s1.grid(row=1, column=0, padx=1, pady=1)

s2 = Scale(
    top_frame, from_=0, to=255, bg="green", orient=HORIZONTAL, length=200, command=col
)
s2.grid(row=2, column=0, pady=1)

s3 = Scale(
    top_frame, from_=0, to=255, bg="blue", orient=HORIZONTAL, length=200, command=col
)
s3.grid(row=3, column=0, pady=1)
master.config(bg="#%02x%02x%02x" % (s1.get(), s2.get(), s3.get()))


left_frame = Frame(master, width=700, height=500)
left_frame.pack(side=LEFT)

left_frame_color = randomcolor()
left_frame.config(bg=left_frame_color)
color1 = left_frame_color
button = Button(master, command=check_distance, width=15, bg="white", text="ΠΑΤΑ ΕΔΩ!")
button.pack(anchor=NE)

mainloop()
