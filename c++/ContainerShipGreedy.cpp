/**
 * @file ContainerShipGreedy.cpp
 * @brief Container Ship Problem.
 * @author marinajcs (GitHub nick)
 *
 * This program solves the container ship loading problem. It determines which containers
 * to load onto a merchant ship to maximize the total weight within the ship's capacity.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * @struct Container
 * @brief Represents a container with a name and weight.
 */
struct Container {
    string name;    ///< Name of the container.
    double weight;  ///< Weight of the container in tons.

    /**
     * @brief Default constructor initializes the container with an empty name and zero weight.
     */
    Container() {
        name = "";
        weight = 0;
    }

    /**
     * @brief Checks if the container is empty (weight is zero).
     * @return true if the container is empty, false otherwise.
     */
    bool isEmpty() {
        return (weight == 0);
    }
};

/**
 * @class ProblemContainerShip
 * @brief Represents the problem of loading containers onto a ship.
 */
class ProblemContainerShip {
private:
    vector<Container> containers; ///< Vector to store containers.
    double maxCapacity;           ///< Maximum loading capacity of the ship.

public:
    /**
     * @brief Default constructor initializes the maximum capacity to zero.
     */
    ProblemContainerShip() {
        maxCapacity = 0;
    }

    /**
     * @brief Get the number of containers in the problem.
     * @return The number of containers.
     */
    const int getNContainers() {
        return containers.size();
    }

    /**
     * @brief Get the maximum loading capacity of the ship.
     * @return The maximum capacity.
     */
    const int getMaxCapacity() {
        return maxCapacity;
    }

    /**
     * @brief Add a container to the problem if it is not empty.
     * @param c The container to add.
     */
    void addContainer(Container c) {
        if (!c.isEmpty()) {
            containers.push_back(c);
        }
    }

    /**
     * @brief Get a container at the specified index.
     * @param n The index of the container.
     * @return The container at the index.
     */
    const Container getContainer(int n) {
        return containers[n];
    }

    /**
     * @brief Get all containers as a vector.
     * @return A vector of containers.
     */
    const vector<Container> getContainers() {
        return containers;
    }

    /**
     * @brief Set the maximum loading capacity of the ship.
     * @param cap The maximum capacity (must be greater than zero).
     */
    void setMaxCapacity(int cap) {
        if (cap > 0) {
            maxCapacity = cap;
        }
    }

    /**
     * @brief Set the name of a container at the specified index.
     * @param idx The index of the container.
     * @param name The name to set.
     */
    void setContainerName(int idx, string name) {
        if (idx >= 0 && idx < getNContainers())
            containers[idx].name = name;
    }

    /**
     * @brief Set the weight of a container at the specified index.
     * @param idx The index of the container.
     * @param w The weight to set.
     */
    void setContainerWeight(int idx, double w) {
        if (idx >= 0 && idx < getNContainers())
            containers[idx].weight = w;
    }

    /**
     * @brief Get the name of a container at the specified index.
     * @param idx The index of the container.
     * @return The name of the container.
     */
    const string getContainerName(int idx) {
        if (idx >= 0 && idx < getNContainers())
            return containers[idx].name;
        return "";
    }

    /**
     * @brief Get the weight of a container at the specified index.
     * @param idx The index of the container.
     * @return The weight of the container.
     */
    const double getContainerWeight(int idx) {
        if (idx >= 0 && idx < getNContainers())
            return containers[idx].weight;
        return 0;
    }
};

/**
 * @brief Comparator function to be used for sorting containers from heaviest to lightest.
 * @param c1 The first container to compare.
 * @param c2 The second container to compare.
 * @return true if c1 is heavier than c2, false otherwise.
 */
bool compareContainer(const Container &c1, const Container &c2) {
    return c1.weight > c2.weight;
}

/**
 * @brief GreedyContainers function implements a greedy algorithm to solve the container ship loading problem.
 * @param p An instance of the problem with containers and ship capacity defined.
 * @return A pair containing the vector of selected containers and a pair of values representing
 * the number of selected containers and their total weight.
 */
pair<vector<Container>, pair<int, double>> GreedyContainers(ProblemContainerShip p) {
    vector<Container> solutionContainers;
    Container c;
    double solutionWeight = 0;
    int solutionSize = 0;
    int problemSize = p.getNContainers();
    double capacity = p.getMaxCapacity();
    vector<Container> containers;

    for (int i = 0; i < problemSize; i++)
        containers.push_back(p.getContainer(i));

    sort(containers.begin(), containers.end(), compareContainer); // to sort containers from highest to lowest weight

    for (int i = 0; i < problemSize && capacity > 0; i++) {
        c = containers.at(i);
        if (c.weight <= capacity) {
            solutionWeight += c.weight;
            capacity -= c.weight;

            solutionContainers.push_back(c);
            solutionSize++;
        }
    }

    pair<int, double> solutionSizeWeight(solutionSize, solutionWeight);
    pair<vector<Container>, pair<int, double>> solution(solutionContainers, solutionSizeWeight);

    return solution;
}

/**
 * @brief Test function sets up a test scenario for the container ship problem.
 *
 * It creates an instance of ProblemContainerShip, adds containers with names and weights,
 * and then uses the GreedyContainers function to find a solution. It prints information
 * about the problem and the solution.
 */
void test() {
    ProblemContainerShip p;
    Container c;
    p.setMaxCapacity(1000);
    string containerNames[10] = {"C-1", "C-9", "C-16", "C-23", "C-30", "C-31", "C-39", "C-55", "C-68", "C-74"};
    int containerWeights[10] = {189, 78, 108, 214, 252, 333, 125, 147, 123, 191};

    // Loop to add containers to the problem
    for (int i = 0; i < 10; i++) {
        c.name = containerNames[i];
        c.weight = containerWeights[i];
        p.addContainer(c);
    }

    cout << "-----------CONTAINER SHIP PROBLEM-----------" << endl;
    cout << "Capacity (tons): " << p.getMaxCapacity() << endl;
    cout << "Number of containers: " << p.getNContainers() << endl;
    cout << "Containers [name, weight]:" << endl;

    // Display information about containers
    for (int i = 0; i < p.getNContainers(); i++) {
        cout << " -> " << (i + 1) << ": " << p.getContainerName(i) << ", " << p.getContainerWeight(i) << endl;
    }

    pair<vector<Container>, pair<int, double>> solution;

    // Solve the container ship problem using the GreedyContainers function
    solution = GreedyContainers(p);
    int solutionSize = solution.second.first;
    int solutionWeight = solution.second.second;

    cout << "-----------SOLUTION (GREEDY)-----------" << endl;
    cout << "Number of containers: " << solutionSize << endl;
    cout << "Containers [name, weight]:" << endl;

    // Display the solution
    for (int i = 0; i < solutionSize; i++) {
        cout << " -> " << (i + 1) << ": " << solution.first[i].name << ", " << solution.first[i].weight << endl;
    }
    cout << "Max. weight (tons): " << solutionWeight << endl;
}

/**
 * @brief The main function calls the test function to run the test scenario for the container ship problem.
 * @return 0 indicating successful execution.
 */
int main() {
    test();
    return 0;
}

/**
 * @note This Greedy algorithm does not guarantee an optimal solution, but it always gives a solution.
 * In the test example, the optimal solution would be:
 * C-31, C-30, C-23, C-68, C-9 (5 containers: 333+252+214+123+78=1000 tons in total)
 * However, this Greedy algorithm gives the following solution:
 * C-31, C-30, C-23, C-74 (4 containers: 333+252+214+191=990 tons in total)
 */
