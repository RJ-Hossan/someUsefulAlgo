# IDS Algorithm

# Class creation
class Node:
    def __init__(self, state, parent=None):
        self.state = state
        self.parent = parent

    def __eq__(self, other):
        return self.state == other.state

    def __hash__(self):
        return hash(self.state)

# DLS method
def depth_limited_search(node, goal_state, actions, depth_limit):
    if node.state == goal_state:
        return node
    elif depth_limit == 0:
        return None
    else:
        connect = False
        for action in actions(node.state):
            child = Node(action, parent=node)
            result = depth_limited_search(child, goal_state, actions, depth_limit - 1)
            if result is not None:
                return result
            connect = True
        return None if connect else "Connectionless"

# IDS method
def iterative_deepening_search(root, target_state, actions, max_depth):
    for depth in range(max_depth + 1):
        result = depth_limited_search(root, target_state, actions, depth)
        if result is not None:
            return result
    return None


initial_state = "A"
target_state = "D"

def actions(state):
    if state == "A":
        return ["B", "C"]
    elif state == "B":
        return ["A", "D"]
    elif state == "C":
        return ["A", "E"]
    elif state == "D":
        return ["B"]
    elif state == "E":
        return ["C"]

root_node = Node(initial_state)

result_node = iterative_deepening_search(root_node, target_state, actions, max_depth=1)

if result_node is not None:
    path = []
    while result_node is not None:
        path.insert(0, result_node.state)
        result_node = result_node.parent
    print("Solution Path: ", " => ".join(path))
else:
    print("No solution found.")
