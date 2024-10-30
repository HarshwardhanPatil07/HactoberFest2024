# Method overloding - When we have same name method but with different argument is called Method Overloding. But Here in Python we donot have the consept of overlodinf and riding  so we can not create two methods with same name.But we can use it indirectly.For ex-:


class student:
    def __init__(self, m1, m2):
        self.m1 = m1
        self.m2 = m2

    def sum(self, a=None, b=None, c=None):
        s = 0
        if a != None and b != None and c != None:
            s = a + b + c
        elif a != None and b != None:
            s = a + b
        else:
            s = a

        return s


s1 = student(4, 5)
print(s1.sum(5 + 6))
print("This is Method Overloding Concept ")

print(" ")

# Method Overriding - This is just simillar as overloding but here we can create another method with same name and same argument also but it only applicable in inheritance . For ex-:


class A:
    def show(self):
        print("In A Show ")


class B(A):
    def show(
        self,
    ):  # As we created same parameter as A in B this is Called Method Overriding.
        print("In B class ")


a1 = A()
a1.show()
b1 = B()
b1.show()
print("This is Method Overridnig Concept   ")
