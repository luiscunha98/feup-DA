/**
 * @file GraphAM.h
 * @brief Declaration of the GraphAM class.
 */

#ifndef DA2_GRAPHAM_H
#define DA2_GRAPHAM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/**
 * @class GraphAM
 * @brief Represents a graph using an adjacency matrix representation.
 */
class GraphAM {
private:
    int numNodes; /**< The number of nodes in the graph */
    // Number of Vertex
    int n;

    //path
    int **path_vals;

    //Shortest path length
    int pathLength{};

    // List of odd nodes
    std::vector<int>odds;


    //euler circuit
    std::vector<int> circuit;/**< Stores Euler circuit*/

    std::vector<int>* adjlist;/**< for Christofide's, */
    float **adjacencyMatrix; /**< The adjacency matrix representing the graph */

public:
    /**
     * @brief Get the number of nodes in the graph.
     * @return The number of nodes.
     */
    int getNumNodes() const;

    /**
     * @brief Get the adjacency matrix of the graph.
     * @return Const reference to the adjacency matrix.
     */
    float ** getAdjacencyMatrix() const;

    /**
     * @brief Parameterized constructor for GraphAM.
     * @param numNodes The number of nodes in the graph.
     */
    explicit GraphAM(int numNodes);

    /**
     * @brief Add an edge to the graph.
     * @param src The source node of the edge.
     * @param dest The destination node of the edge.
     * @param dist The weight/distance of the edge.
     */
    void addEdge(int src, int dest, float dist);

    /**
     * @brief Solve the Traveling Salesman Problem (TSP) using the held-karp algorithm.
     * @param v Vector of boolean values indicating visited nodes.
     * @param currPos The current position in the TSP path.
     * @param n The total number of nodes.
     * @param count The count of visited nodes in the TSP path.
     * @param cost The cost of the TSP path.
     * @param ans Reference to store the minimum TSP path cost.
     * @param path Vector to store the TSP path.
     */
    void tsp(std::vector<bool>& v, int currPos, int n, int count, float cost, float& ans, std::vector<int>& path);

    /**
     * @brief Get the weight/distance between two nodes in the graph.
     * @param node1 The first node.
     * @param node2 The second node.
     * @return The weight/distance between the two nodes.
     */
    float getWeight(int node1, int node2) const;

    float getAt(int x,int y);

    int getN() const;

    int &getPathLength() ;

    std::vector<int> &getCircuit() ;

    void addToAdjList(int i,int j);

    int getadjSizeAt(int i);

    void pushToOdd(int i);

    const std::vector<int> & getOdds() const;

    virtual ~GraphAM();

    std::vector<int> getadjAt(int i);

    void setPathValLongInt(long i,int j,float val);

    int getPathValAt(int i, int j);

    //void fillMatrix();
};

#endif //DA2_GRAPHAM_H
