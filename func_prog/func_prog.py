#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
from functools import reduce

# map
squares = list(map(lambda x: x * x, [0, 1, 2, 3, 4]))
print(squares)

names = ['Mary', 'Isla', 'Sam']
secret_names = list(map(lambda x: random.choice(['Mr. Pink',
                                                 'Mr. Orange',
                                                 'Mr. Blonde']), names))
print(secret_names)

# reduce
sum = reduce(lambda a, x: a + x, [0, 1, 2, 3, 4])
print(sum)

sentences = ['Mary read a story to Sam and Isla.',
             'Isla cuddled Sam.',
             'Sam chortled.']
sam_count = reduce(lambda a, x: a + x.count('Sam'),
                   sentences,
                   0)
print(sam_count)

# map, reduce, filter
people = [{'name': 'Mary', 'height': 160},
          {'name': 'Isla', 'height': 80},
          {'name': 'Sam'}]
heights = list(map(lambda x: x['height'],
               list(filter(lambda x: 'height' in x, people))))
print(heights)
