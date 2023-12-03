import heapq
import networkx as nx
import matplotlib.pyplot as plt

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

    G = nx.Graph()  # Create a graph for visualization
    G.add_node(start_node.state)

    while frontier:
        current_node = heapq.heappop(frontier)

        if current_node.state == goal_state:
            path = []
            while current_node:
                path.insert(0, current_node.state)
                current_node = current_node.parent
            return path, G

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
                G.add_edge(current_node.state, neighbor_node.state)

    return None, G  # No path found

# Example usage:
def get_neighbors(state):
    # Define how to get neighbors for a given state
    # For example, for a grid, return the neighboring cells
    x, y = state
    neighbors = [
        ((x + 1, y), 1),  # Right neighbor with cost 1
        ((x - 1, y), 1),  # Left neighbor with cost 1
        ((x, y + 1), 1),  # Up neighbor with cost 1
        ((x, y - 1), 1),  # Down neighbor with cost 1
    ]
    return neighbors

def heuristic(state):
    # Define a heuristic function for estimating the cost to reach the goal from a given state
    # Example: Euclidean distance heuristic
    goal_state = (4, 4)  # Replace with your actual goal state
    return ((state[0] - goal_state[0]) ** 2 + (state[1] - goal_state[1]) ** 2) ** 0.5

start_state = (0, 0)  # Replace with your actual start state
goal_state = (0, 3)   # Replace with your actual goal state

path, graph = astar_search(start_state, goal_state, get_neighbors, heuristic)

if path:
    print("Path found:", path)
    pos = nx.spring_layout(graph)  # Layout for visualization
    nx.draw(graph, pos, with_labels=True, font_weight='bold', node_size=700)
    plt.show()
else:
    print("No path found.")
