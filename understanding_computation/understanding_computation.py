#!/usr/bin/env python3


# define virtual machine
class Machine():
    def __init__(self, expression, environment):
        self.expression = expression
        self.environment = environment

    def run(self):
        while self.expression.reducible():
            self.expression = self.expression.reduce(self.environment)
            print(self.expression)


# define variable
class Variable():
    def __init__(self, name):
        self.name = name

    def reducible(self):
        return True

    def __repr__(self):
        return self.name

    def reduce(self, environment):
        return environment[self.name]


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
        str_l = str(self.left_value)
        str_r = str(self.right_value)
        return str_l + " " + self.get_symbol() + " " + str_r

    def __init__(self, left_value, right_value):
        self.left_value = left_value
        self.right_value = right_value

    def __repr__(self):
        return self.to_str()

    def reducible(self):
        return True

    def not_reducible(self):
        pass

    def ret_self(self, l, r):
        return Operator(l, r)

    def reduce(self, environment):
        if self.left_value.reducible():
            return self.ret_self(self.left_value.reduce(environment),
                                 self.right_value)
        if self.right_value.reducible():
            return self.ret_self(self.left_value,
                                 self.right_value.reduce(environment))
        else:
            return self.not_reducible()


class LessThan(Operator):
    def get_symbol(self):
        return "<"

    def ret_self(self, l, r):
        return LessThan(l, r)

    def not_reducible(self):
        return Boolean(self.left_value.value < self.right_value.value)


class Add(Operator):
    def get_symbol(self):
        return "+"

    def ret_self(self, l, r):
        return Add(l, r)

    def not_reducible(self):
        return Number(self.left_value.value + self.right_value.value)


class Multiply(Operator):
    def get_symbol(self):
        return "*"

    def ret_self(self, l, r):
        return Multiply(l, r)

    def not_reducible(self):
        return Number(self.left_value.value * self.right_value.value)


if __name__ == "__main__":
    # Test +/* and number
    expression = Add(Number(5), Multiply(Number(5), Number(2)))
    environment = {}
    print(expression)
    machine = Machine(expression, environment)
    machine.run()

    # Test < and boolean
    expression = LessThan(Number(4), Number(2))
    environment = {}
    print(expression)
    machine = Machine(expression, environment)
    machine.run()

    # Test use Variable
    expression = Add(Variable('y'), Multiply(Variable('x'), Number(3)))
    environment = {'x': Number(5), 'y': Number(10)}
    print(expression)
    machine = Machine(expression, environment)
    machine.run()
