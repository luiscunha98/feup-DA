/**
 * @file Algorithms.h
 * @brief Declaration of the Algorithms class.
 */

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>

/**
 * @class Algorithms
 * @brief Contains static methods for various algorithms.
 */
class Algorithms {

public:
    /**
     * @brief Performs the backtracking algorithm on a Traveling Salesman Problem (TSP) graph.
     * @param filename The name of the file containing the graph data.
     * Time Complexity is factorial , for toy graphs it works for the others the inc rease in time is too much (estimate:n=20 3 * (20!/11!) = 3 * (20 * 19 * 18 * ... * 2 * 1) / (11 * 10 * 9 * ... * 2 * 1) ~ 12,988,800s)
     * given that for n=11 rakes about 3 seconds
     */
    static void backtrackingTG(const std::string& filename);
    static void backtrackingRWG( std::string& filename);


    /**
     * @brief Performs the triangular approximation algorithm on a Traveling Salesman Problem (TSP) graph.
     * @param filename The name of the file containing the graph data.
     * Algoritmo dos slides, alternativa para 4.2, complexidade O(V^2): , 2 approximation
     */
    static void triangularapproximationTG(const std::string& filename);

    /**
     * @brief Performs the Nearest Neighbor heuristic on a Traveling Salesman Problem (TSP) is part of Other Heuristics..
     * @param filename The name of the file containing the graph data.
     * O(V^2)
     */
    static void nearestNeighborTSP(const std::string& filename);

    static void triangularapproximationRWG(const std::string &filename);
    /**
     * @brief Performs the Two-Opt heuristic on a Traveling Salesman Problem (TSP) is part of Other Heuristics.
     * @param filename The name of the file containing the graph data.
     */
    static void twoOptTSP(const std::string& filename);
    /**
 * @brief Executes the Christofides algorithm on a graph read from a file.
 *
 * This function implements the Christofides algorithm to find an approximate solution for the Traveling Salesman Problem (TSP).
 * It reads a graph from a file and performs the following steps:
 * 1. Reads the graph from the file in either RWG or TG format.
 * 2. Finds the Minimum Spanning Tree (MST) of the graph.
 * 3. Computes a perfect matching on the MST to create a Eulerian graph.
 * 4. Iterates over each vertex to find the best path starting from the first vertex.
 * 5. Calculates the Euler tour of the best path.
 * 6. Converts the Euler tour to a Hamiltonian path by removing duplicate vertices.
 * 7. Prints the result of the algorithm and the final Hamiltonian path.
 *
 * @param file The name of the file containing the graph data.
 * A complexidade e dominada pela função de matching , O(n^3) como não e minimal matching
 */
    static void christofides(std::string& file);
};

#endif // ALGORITHMS_H
