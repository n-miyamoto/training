
# define virtual machine
class Machine():
    def __init__(self, expression):
        self.expression = expression
    def run(self):
        while self.expression.reducible():
            self.expression = self.expression.reduce()   
            print(self.expression)

# define literals
class Literal():
    def __init__(self, value):
        self.value = value
    def reducible(self):
        return False
    def __repr__(self):
        return str(self.value)

class Number(Literal):
    pass

class Boolean(Literal):
    pass

# define operator
class Operator():
    def get_symbol(self):
        return "?"
    def to_str(self):
        return str(self.left_value) + " " + self.get_symbol() + " " + str(self.right_value)
    def __init__(self, left_value, right_value ):
        self.left_value = left_value
        self.right_value = right_value
    def __repr__(self):
        return self.to_str()
    def reducible(self):
        return True
    def not_reducible(self):
        pass
    def reduce(self):
        if self.left_value.reducible():
            return LessThan(self.left_value.reduce(), self.right_value)
        if self.right_value.reducible():
            return LessThan(self.left_value, self.right_value.reduce())
        else:
            return self.not_reducible()

class LessThan(Operator):
    def get_symbol(self):
        return "<"
    def not_reducible(self):
        return Boolean(self.left_value.value < self.right_value.value)

class Add(Operator):
    def get_symbol(self):
        return "+"
    def not_reducible(self):
        return Number(self.left_value.value + self.right_value.value)

class Multiply(Operator):
    def get_symbol(self):
        return "*"
    def reduce(self):
        if self.left_value.reducible():
            return Add(self.left_value.reduce(), self.right_value)
        if self.right_value.reducible():
            return Add(self.left_value, self.right_value.reduce())
        else:
            return Number(self.left_value.value * self.right_value.value)

if __name__ == "__main__":
    #Test +/* and number
    expression = Add(Number(5),Multiply(Number(5),Number(2)))
    print(expression)
    machine = Machine(expression)
    machine.run()

    #Test < and boolean
    expression = LessThan(Number(4),Number(2))
    print(expression)
    machine = Machine(expression)
    machine.run()

