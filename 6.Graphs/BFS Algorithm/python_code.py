import collections

def bfs(graph, start):
    visited = set()
    queue = collections.deque([start])

    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)

def main():
    graph = {
        0: [1, 2],
        1: [0, 2],
        2: [0, 1, 3],
        3: [2]
    }

    print("Breadth First Search:")
    bfs(graph, 0)

if __name__ == '__main__':
    main()