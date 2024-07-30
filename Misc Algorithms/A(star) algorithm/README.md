A* is a widely used pathfinding algorithm in the field of computer science and artificial intelligence. It efficiently finds the shortest path between nodes or points on a weighted graph, taking into account both the cost of reaching a node and an estimate of the cost required to reach the goal from that node. Here's how it works:

### Working of A* Algorithm:

1. **Initialization**: 
   - Start with the initial node and add it to the open list. 
   - Set its `g` value (the cost of the path from the start node to the current node) to 0.
   - Calculate the heuristic cost `h` from the current node to the goal node.
   - Calculate the total cost `f = g + h`.

2. **Loop**:
   - While the open list is not empty:
     - Select the node with the lowest `f` value from the open list. This is the current node.
     - Move the current node from the open list to the closed list to mark it as visited.
     - If the current node is the goal node, the algorithm terminates with the path found.
     - Otherwise, expand the current node by examining its neighboring nodes.

3. **Neighbor Expansion**:
   - For each neighboring node of the current node:
     - Calculate the tentative `g` value, which is the sum of the `g` value of the current node and the cost to reach the neighboring node.
     - If the neighboring node is not in the open list or its tentative `g` value is lower than its current `g` value:
       - Update the `g` value of the neighboring node.
       - Calculate the heuristic cost `h` from the neighboring node to the goal node.
       - Calculate the total cost `f = g + h`.
       - Set the parent of the neighboring node to the current node.
       - If the neighboring node is not in the open list, add it to the open list.

4. **Termination**:
   - If the open list is empty, and the goal node has not been reached, then there is no path from the start node to the goal node, and the algorithm terminates.

### Algorithm:
```
function AStar(start, goal)
    openList := {start}
    closedList := {}
    while openList is not empty
        current := node in openList with the lowest f_cost
        if current == goal
            return reconstruct_path(goal)
        remove current from openList
        add current to closedList
        for each neighbor of current
            if neighbor is not traversable or neighbor is in closedList
                continue
            tentative_g := g_cost of current + cost between current and neighbor
            if neighbor is not in openList or tentative_g < g_cost of neighbor
                set g_cost of neighbor to tentative_g
                set h_cost of neighbor to heuristic cost from neighbor to goal
                set f_cost of neighbor to g_cost of neighbor + h_cost of neighbor
                set parent of neighbor to current
                if neighbor is not in openList
                    add neighbor to openList
    return failure
```

### Key Components:
- **g(n)**: The cost of the cheapest path from the start node to node `n` discovered so far.
- **h(n)**: A heuristic function that estimates the cost of the cheapest path from `n` to the goal node. It should be admissible (never overestimates the actual cost) and consistent (satisfies the triangle inequality).
- **f(n) = g(n) + h(n)**: The total estimated cost of the cheapest path from the start node to the goal node passing through `n`.
- **Open List**: A list of nodes to be evaluated, sorted by `f` value.
- **Closed List**: A list of nodes already evaluated.

A* is effective in finding the shortest path in many practical situations, but its performance heavily depends on the heuristic function used and the characteristics of the graph.