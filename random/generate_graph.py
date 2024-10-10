import random

def generate_random_connected_graph(N, M):
    # if M < N - 1:
    #     raise ValueError("Number of edges must be at least N-1 for the graph to be connected.")

    edges = []
    connected_nodes = set()
    # unconnected_nodes = set(range(1, N + 1)) # 1-indexed :P

    # # Step 1: Create a spanning tree to ensure the graph is connected
    # current_node = unconnected_nodes.pop()
    # connected_nodes.add(current_node)

    # while unconnected_nodes:
    #     next_node = unconnected_nodes.pop()
    #     connected_node = random.choice(list(connected_nodes))
    #     edges.append((connected_node, next_node))
    #     connected_nodes.add(next_node)

    # Step 2: Add random edges until we reach M edges
    while len(edges) < M:
        u, v = random.sample(range(0, N), 2)
        if u != v and (u, v) not in edges and (v, u) not in edges:
            edges.append((u, v))

    return edges

# Example usage
N = 5  # Number of nodes
M = random.randrange(0, N * (N - 1) / 2)  # Number of edges
# okay what do we learn from this
# you can use sets in python
# random.choice
# can change sets to list stupid
# not in..
edges = generate_random_connected_graph(N, M)
with open("out.txt", "w") as file:
    file.write(f"{N} {M}\n")
    for u, v in edges:
        file.write(f"{u} {v}\n")
file.close