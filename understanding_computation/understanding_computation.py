
class Machine():
    def __init__(self, expression):
        self.expression = expression
    def run(self):
        while self.expression.reducible():
            print(self.expression)
            self.expression = self.expression.reduce()   
            print(self.expression)

class Number():
    def __init__(self, value):
        self.value = value
    def reducible(self):
        return False
    def __repr__(self):
        return str(self.value)

class Add():
    def __init__(self, left_value, right_value ):
        self.left_value = left_value
        self.right_value = right_value
    def __repr__(self):
        return str(self.left_value) + " + " + str(self.right_value)
    def reducible(self):
        return True
    def reduce(self):
        if self.left_value.reducible():
            return Add(self.left_value.reduce(), self.right_value)
        if self.right_value.reducible():
            return Add(self.left_value, self.right_value.reduce())
        else:
            return Number(self.left_value.value + self.right_value.value)

class Multiply():
    def __init__(self, left_value, right_value ):
        self.left_value = left_value
        self.right_value = right_value
    def __repr__(self):
        return str(self.left_value) + " * " + str(self.right_value)
    def reducible(self):
        return True
    def reduce(self):
        if self.left_value.reducible():
            return Add(self.left_value.reduce(), self.right_value)
        if self.right_value.reducible():
            return Add(self.left_value, self.right_value.reduce())
        else:
            return Number(self.left_value.value * self.right_value.value)



if __name__ == "__main__":
    expression = Add(Number(5),Multiply(Number(5),Number(2)))
    print(expression)

    machine = Machine(expression)

    machine.run()

