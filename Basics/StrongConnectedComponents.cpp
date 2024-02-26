#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

class StrongConnectedComponents {
private:
    int leader;
    std::vector<int> leader_node;
    std::vector<int> explore;
    std::vector<int> finishing_time_of_node;
    int finishing_time;
    int number_of_nodes;
    std::stack<int> stack;
    std::unordered_map<int, int> finishing_time_map;

public:
    StrongConnectedComponents(int nodes) : number_of_nodes(nodes) {
        leader_node.resize(number_of_nodes + 1);
        explore.resize(number_of_nodes + 1);
        finishing_time_of_node.resize(number_of_nodes + 1);
        finishing_time = 1;
    }

    void strongConnectedComponent(std::vector<std::vector<int>>& adjacency_matrix) {
        for (int i = number_of_nodes; i > 0; i--) {
            if (explore[i] == 0) {
                dfs_1(adjacency_matrix, i);
            }
        }

        std::vector<std::vector<int>> rev_matrix(number_of_nodes + 1, std::vector<int>(number_of_nodes + 1, 0));
        for (int i = 1; i <= number_of_nodes; i++) {
            for (int j = 1; j <= number_of_nodes; j++) {
                if (adjacency_matrix[i][j] == 1) {
                    rev_matrix[finishing_time_of_node[j]][finishing_time_of_node[i]] = 1;
                }
            }
        }

        explore.assign(number_of_nodes + 1, 0);
        leader_node.assign(number_of_nodes + 1, 0);

        for (int i = number_of_nodes; i > 0; i--) {
            if (explore[i] == 0) {
                leader = i;
                dfs_2(rev_matrix, i);
            }
        }
    }

    void dfs_1(std::vector<std::vector<int>>& adjacency_matrix, int source) {
        explore[source] = 1;
        stack.push(source);

        while (!stack.empty()) {
            int element = stack.top();
            int i = 1;
            while (i <= number_of_nodes) {
                if (adjacency_matrix[element][i] == 1 && explore[i] == 0) {
                    stack.push(i);
                    explore[i] = 1;
                    element = i;
                    i = 1;
                    continue;
                }
                i++;
            }
            int popped = stack.top();
            stack.pop();
            int time = finishing_time++;
            finishing_time_of_node[popped] = time;
            finishing_time_map[time] = popped;
        }
    }

    void dfs_2(std::vector<std::vector<int>>& rev_matrix, int source) {
        explore[source] = 1;
        leader_node[finishing_time_map[source]] = leader;
        stack.push(source);

        while (!stack.empty()) {
            int element = stack.top();
            int i = 1;
            while (i <= number_of_nodes) {
                if (rev_matrix[element][i] == 1 && explore[i] == 0) {
                    if (leader_node[finishing_time_map[i]] == 0)
                        leader_node[finishing_time_map[i]] = leader;
                    stack.push(i);
                    explore[i] = 1;
                    element = i;
                    i = 1;
                    continue;
                }
                i++;
            }
            stack.pop();
        }
    }

    void printStrongConnectedComponents() {
        std::cout << "The Strong Connected Components are:\n";
        for (int i = 1; i < leader_node.size(); i++) {
            std::cout << "Node " << i << " belongs to SCC " << leader_node[i] << std::endl;
        }
    }
};

int main() {
    int number_of_nodes;

    std::cout << "Enter the number of nodes in the graph: ";
    std::cin >> number_of_nodes;

    std::vector<std::vector<int>> adjacency_matrix(number_of_nodes + 1, std::vector<int>(number_of_nodes + 1, 0));

    std::cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= number_of_nodes; i++)
        for (int j = 1; j <= number_of_nodes; j++)
            std::cin >> adjacency_matrix[i][j];

    StrongConnectedComponents strong(number_of_nodes);
    strong.strongConnectedComponent(adjacency_matrix);
    strong.printStrongConnectedComponents();

    return 0;
}

//Output:-

The Strong Connected Components are:
Node 1 belongs to SCC 1
Node 2 belongs to SCC 2
Node 3 belongs to SCC 3
Node 4 belongs to SCC 4
Node 5 belongs to SCC 5
Node 6 belongs to SCC 6
Node 7 belongs to SCC 7
Node 8 belongs to SCC 8

