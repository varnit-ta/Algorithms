#include <iostream>
#include <vector>
#include <iomanip>

class Graph {
public:
    Graph(int size) : size(size) {
        adjMatrix.resize(size, std::vector<int>(size, 0));
    }

    void add_edge(int v1, int v2) {
        if (v1 == v2) {
            std::cout << "Same vertex " << v1 << " and " << v2 << std::endl;
            return;
        }
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    void remove_edge(int v1, int v2) {
        if (adjMatrix[v1][v2] == 0) {
            std::cout << "No edge between " << v1 << " and " << v2 << std::endl;
            return;
        }
        adjMatrix[v1][v2] = 0;
        adjMatrix[v2][v1] = 0;
    }

    int get_size() const {
        return size;
    }

    void print_matrix() const {
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                std::cout << std::setw(4) << val << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int size;
    std::vector<std::vector<int>> adjMatrix;
};

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.print_matrix();

    return 0;
}
