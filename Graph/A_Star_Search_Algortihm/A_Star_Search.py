import heapq

class Node:
    def __init__(self, state, parent=None, cost=0, heuristic=0):
        self.state = state
        self.parent = parent
        self.cost = cost
        self.heuristic = heuristic

    def __lt__(self, other):
        return (self.cost + self.heuristic) < (other.cost + other.heuristic)

def astar_search(start_state, goal_state, get_neighbors, heuristic):
    start_node = Node(state=start_state, cost=0, heuristic=heuristic(start_state))
    frontier = [start_node]
    explored = set()

    while frontier:
        current_node = heapq.heappop(frontier)

        if current_node.state == goal_state:
            path = []
            while current_node:
                path.insert(0, current_node.state)
                current_node = current_node.parent
            return path

        explored.add(current_node.state)

        for neighbor_state, cost in get_neighbors(current_node.state):
            if neighbor_state not in explored:
                neighbor_node = Node(
                    state=neighbor_state,
                    parent=current_node,
                    cost=current_node.cost + cost,
                    heuristic=heuristic(neighbor_state),
                )
                heapq.heappush(frontier, neighbor_node)

    return None  # No path found

def get_neighbors(state):
    x, y = state
    neighbors = [
        ((x + 1, y), 1), 
        ((x - 1, y), 1),  
        ((x, y + 1), 1),  
        ((x, y - 1), 1),
    ]
    return neighbors

def heuristic(state):
    goal_state = (0, 3)
    return ((state[0] - goal_state[0]) ** 2 + (state[1] - goal_state[1]) ** 2) ** 0.5

start_state = (0, 0)
goal_state = (0, 3)
path = astar_search(start_state, goal_state, get_neighbors, heuristic)

if path:
    print("Path found:", path)
else:
    print("No path found.")
