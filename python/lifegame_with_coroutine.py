from collections import namedtuple

ALIVE = '*' 
EMPTY = '_'

Query = namedtuple('Query', ('y', 'x'))

def count_neighbors(y, x):
    n_ = yield Query(y + 1, x + 0)
    ne = yield Query(y + 1, x + 1)
    e_ = yield Query(y + 0, x + 1)
    se = yield Query(y - 1, x + 1)
    s_ = yield Query(y - 1, x + 0)
    sw = yield Query(y - 1, x - 1)
    w_ = yield Query(y + 0, x - 1)
    nw = yield Query(y + 1, x - 1)

    neighbor_states = [n_, ne, e_, se, s_, sw, w_, nw]
    count = 0
    for state in neighbor_states:
        if state == ALIVE:
            count += 1
        return count

def game_logic(state, neighbors):
    if state is ALIVE:
        if neighbors < 2:
            return EMPTY
        elif neighbors > 3:
            return EMPTY
    else:
        if neighbors == 3:
            return ALIVE
    return state

Transition = namedtuple('Transition', ('y', 'x', 'state'))

def step_cells(y, x):
    state = yield Query(y, x)
    neighbors = yield from count_neighbors(y, x)
    next_state = game_logic(state, neighbors)
    yield Transition(y, x, next_state)

TICK = object()

def simulate(height, width):
    while True:
        for y in range(height):
            for x in range(width):
                yield from step_cells(y, x)
        yield TICK

class Grid(object):
    def __init__(self, height, width):
        self.height = height
        self.width = width
        self.rows = []
        for _ in range(self.height):
            self.rows.append([EMPTY] * self.width)
    
    def __str__(self):
        s = ''
        for y in range(self.height):
            for x in range(self.width):
                s+= self.rows[y % self.height][x % self.width]
            s+='\n'
        s+= '----------'
        return s

    def query(self,y,x):
        return self.rows[y % self.height][x % self.width]

    def assign(self, y, x, state):
        self.rows[y % self.height][x % self.width] = state
    
def live_a_generation(grid, sim):
    progeny = Grid(grid.height, grid.width)
    item = next(sim)
    while item is not TICK:
        if isinstance(item, Query):
            state = grid.query(item.y, item.x)
            item = sim.send(state)
        else:
            progeny.assign(item.y, item.x, item.state)
            item = next(sim)
        return progeny


grid = Grid(10, 5)
grid.assign(0, 3, ALIVE)
print(grid)

sim = simulate(grid.height, grid.width)
for i in range(5):
    print(grid)
    grid = live_a_generation(grid, sim)
