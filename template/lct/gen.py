import random
import os
os.chdir("C:\\Users\\benja\\VSC\\code\\template\\lct")
class DisjointSetUnion:
    """Union-Find data structure to track connected components."""
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.rank = [1] * (n + 1)

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            # Union by rank
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1
            return True
        return False  # u and v are already in the same component

def generate_test_case(N, Q, output_file, seed=None):
    """
    Generate a single test case for N nodes and Q queries, ensuring no cycles.
    Args:
        N (int): Number of nodes.
        Q (int): Number of queries.
        output_file (str): File path to write the test case.
        seed (int, optional): Random seed for reproducibility.
    """
    if seed is not None:
        random.seed(seed)

    dsu = DisjointSetUnion(N)
    edges_present = set()

    # Query types: add (link), rem (cut), conn (connected)
    add_weight = 0.6
    rem_weight = 0
    conn_weight = 0.4

    with open(output_file, "w") as file:
        file.write(f"{N} {Q}\n")

        for _ in range(Q):
            op_type = random.random()

            if op_type < add_weight:
                # Generate an 'add' query (link)
                u = random.randint(1, N)
                v = random.randint(1, N)
                while v == u:
                    v = random.randint(1, N)

                edge = (min(u, v), max(u, v))
                if edge not in edges_present and dsu.union(u, v):
                    edges_present.add(edge)
                    file.write(f"add {u} {v}\n")
                else:
                    # Fallback to 'conn' if we cannot add this edge
                    file.write(f"conn {u} {v}\n")

            elif op_type < add_weight + rem_weight:
                # Generate a 'rem' query (cut)
                if edges_present:
                    edge = random.sample(edges_present, 1)[0]
                    edges_present.remove(edge)
                    u, v = edge
                    dsu.parent[v] = v  # Simulate disconnection in DSU
                    file.write(f"rem {u} {v}\n")
                else:
                    # Fallback to 'conn' if no edges to remove
                    u = random.randint(1, N)
                    v = random.randint(1, N)
                    while v == u:
                        v = random.randint(1, N)
                    file.write(f"conn {u} {v}\n")

            else:
                # Generate a 'conn' query (connected)
                u = random.randint(1, N)
                v = random.randint(1, N)
                while v == u:
                    v = random.randint(1, N)
                file.write(f"conn {u} {v}\n")


def main():
    N = 100000  # Maximum nodes
    Q = 100000  # Maximum queries
    output_file = "test_case.txt"  # Output file name
    generate_test_case(N, Q, output_file)
    print(f"Test case written to {output_file}")


if __name__ == "__main__":
    main()