import turtle

screen = turtle.Screen()
screen.bgcolor("white")

dino = turtle.Turtle()
dino.shape("turtle")
dino.color("green")
dino.speed(0)

dino.penup()
dino.goto(-100, 0)
dino.pendown()
dino.begin_fill()
dino.forward(50)
dino.left(90)
dino.forward(20)
dino.left(90)
dino.forward(30)
dino.right(90)
dino.forward(20)
dino.left(90)
dino.forward(20)
dino.left(90)
dino.forward(20)
dino.right(90)
dino.forward(20)
dino.left(90)
dino.forward(30)
dino.left(90)
dino.forward(20)
dino.end_fill()

eye = turtle.Turtle()
eye.shape("circle")
eye.color("black")
eye.speed(0)

# Draw the eye
eye.penup()
eye.goto(-80, 20)
eye.pendown()
eye.begin_fill()
eye.circle(5)
eye.end_fill()

turtle.hideturtle()

turtle.done()
