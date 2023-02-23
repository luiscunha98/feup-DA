// By: Gonçalo Leão

#ifndef DA_TP1_CLASSES_EXERCISES_H
#define DA_TP1_CLASSES_EXERCISES_H

#include "../data_structures/Graph.h"

#include <stack>

class IntroGraph: public Graph {
public:
    // Ex 1
    bool removeEdge(const int &source, const int &dest);
    bool removeVertex(const int &id);

    // Ex 2
    std::vector<int> dfs(const int & source) const;

    // Ex 3
    std::vector<int> bfs(const int & source) const;

    // Ex 4
    std::vector<int> topsort() const;

    // Ex 5
    bool isDAG() const;

    // Ex 6
    std::vector<std::vector<int>> computeSCCs() const;
protected:
    /*
     * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
     * Updates a parameter with the list of visited node contents.
     */
    void dfsVisit(Vertex *v, std::vector<int> & res) const;

    /*
     * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
     * Returns false (not acyclic) if an edge to a vertex in the stack is found.
     */
    bool dfsIsDAG(Vertex *v) const;

    /*
     * Auxiliary function to perform the first DFS on the Kosaraju-Sharir algorithm.
     */
    void firstDFSKosarajuSharir(Vertex *v, std::stack<Vertex *> &vertexStack) const;

    /*
     * Auxiliary function to perform the second DFS on the Kosaraju-Sharir algorithm.
     */
    void secondDFSKosarajuSharir(Vertex *v, std::vector<int> & res) const;
};

// Ex 8
std::vector<int> heapSort(std::vector<int> v);

// Ex 9
int kthSmallest(unsigned int k, std::vector<int> v);

#endif //DA_TP1_CLASSES_EXERCISES_H
