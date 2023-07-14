#ifndef DA1_NEWGRAPH_H
#define DA1_NEWGRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "VertexEdge.h"
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const string &name) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(string name, string district, string municipality, string township, string line);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const string &sourc, const string &dest, double w, string service);

    Edge* getEdge(Vertex* v1, Vertex* v2);

    int getNumVertex() const;

    vector<Vertex *> getVertexSet() const;

    void edmondsKarp(string source, string target);

    void dijkstra(Vertex *source, Vertex *target, vector<Vertex*>& path);

    static Graph createReducedGraph(const Graph& Graph, const string& line, int k);

protected:
    vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexNamex(const string &name) const;

    void testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual);
    bool findAugmentingPath(Vertex *s, Vertex *t);
    double findMinResidualAlongPath(Vertex *s, Vertex *t);
    void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);

};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif //DA1_NEWGRAPH_H
