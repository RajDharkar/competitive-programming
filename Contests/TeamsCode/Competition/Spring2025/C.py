from collections import defaultdict

# Graph structure
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C']
}

def count_paths(a, b, c, d):
    target = {'A': a, 'B': b, 'C': c, 'D': d}
    total_steps = a + b + c + d

    result = 0

    def dfs(curr, path, counts):
        nonlocal result

        # Prune: if any letter is visited more than allowed
        if any(counts[x] > target[x] for x in "ABCD"):
            return
        
        if len(path) == total_steps:
            if curr == 'A' and counts == target:
                result += 1
            return
        
        for neighbor in graph[curr]:
            counts[neighbor] += 1
            path.append(neighbor)
            dfs(neighbor, path, counts)
            path.pop()
            counts[neighbor] -= 1

    counts = defaultdict(int)
    counts['A'] = 1
    dfs('A', ['A'], counts)
    return result

# Try the known test case
print("Expected: 6 | Simulated:", count_paths(3, 1, 2, 1))

# Try another
print("Expected: 18 | Simulated:", count_paths(4, 2, 2, 1))

# Try something else
print("Expected: 0 | Simulated:", count_paths(2, 2, 1, 1))  # Violates a + d != b + c + 1
