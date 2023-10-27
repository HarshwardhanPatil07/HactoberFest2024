# So in Python we avoid Function Overriding using " Super().function_def() "
class Dog:
    def __init__(self):
        print("Woof Woof")

    def pee(self):
        print("I Will Pee")


class Puppy(Dog):
    def pee(self):
        super().pee()  # Whenever we use Superclass
        print("Go to the park")


p = Puppy()
p.pee()
