#include <set>
#include <map>
#include "newGraph.h"

using namespace std;

int Graph::getNumVertex() const {
    return vertexSet.size();
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */

/**
@brief Finds a vertex in the graph given its name.
This function iterates through the vertex set of the graph and returns the vertex with the given name, or nullptr if no such vertex exists.
@param name The name of the vertex to be found.
@return A pointer to the vertex with the given name, or nullptr if no such vertex exists.
Time complexity: O(V), where V is the number of vertices in the graph. The function iterates through the vertex set, which has at most V vertices, until it finds the vertex with the given name or reaches the end of the set. Therefore, the worst-case time complexity is proportional to the number of vertices in the graph.
*/

Vertex * Graph::findVertex(const string &name) const {
    for (auto v : vertexSet)
        if (v->getName() == name)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */

/**
@brief Calculates the minimum weight along a given path.
This function iterates through each vertex in the given path and checks each adjacent edge to find the one connecting the current vertex to the next one. It returns the minimum weight found among these edges.
@param path A vector of pointers to vertices representing the path.
@return The minimum weight along the path.
@complexity O(E), where E is the number of edges in the graph.
*/

int Graph::findVertexNamex(const string &name) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getName() == name)
            return i;
    return -1;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */

/**
@brief Adds a vertex to the graph with the specified name, district, municipality, township, and line.
@param name Name of the vertex to add.
@param district District of the vertex to add.
@param municipality Municipality of the vertex to add.
@param township Township of the vertex to add.
@param line Line of the vertex to add.
@return True if the vertex was successfully added, false otherwise.
This function creates a new vertex with the specified parameters and adds it to the graph's vertex set.
If a vertex with the same name already exists in the graph, the function returns false and does not add the vertex.
Time complexity: O(n), where n is the number of vertices in the graph.
*/

bool Graph::addVertex(string name, string district, string municipality, string township, string line) {
    if (findVertex(name) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(name, district, municipality, township, line));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */

/**
@brief Adds a new edge to the graph with the specified weight and service between the source and destination vertices.
If either the source or destination vertex does not exist in the graph, the function returns false and the edge is not added.
Otherwise, the edge is added to the adjacency list of the source vertex and the function returns true.
@param sourc Name of the source vertex.
@param dest Name of the destination vertex.
@param w Weight of the edge.
@param service Name of the service associated with the edge.
@return True if the edge was added successfully, false otherwise.
@note This function assumes that the graph is undirected, so it adds the same edge in both directions (i.e., from sourc to dest and from dest to sourc).
*/

bool Graph::addEdge(const string &sourc, const string &dest, double w, string service) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w, service);
    return true;
}

/**
@brief Finds the edge connecting two given vertices in the graph.
This function searches for an edge that connects the two given vertices in the graph.
It checks all the adjacent edges of the first vertex and returns the edge that connects
the first vertex to the second vertex, if such an edge exists. If there is no edge
connecting the two vertices, it returns a nullptr.
@param v1 Pointer to the first vertex.
@param v2 Pointer to the second vertex.
@return Pointer to the edge connecting the two vertices, or nullptr if there is no such edge.
@complexity O(V), where V is the number of vertices in the graph. In the worst case, all
the adjacent edges of the first vertex need to be checked before finding the edge that
connects the two vertices, which takes O(V) time.
*/

Edge* Graph::getEdge(Vertex* v1, Vertex* v2) {
    for (auto e : v1->getAdj()) {
        if (e->getDest() == v2)
            return e;
    }
    return nullptr;
}

/**
@brief Deletes a 2D integer array.
This function deletes a 2D integer array by iterating through each row and then
deleting the row itself. The function ensures that the passed array pointer is not a nullptr before attempting to delete it.
@param m Pointer to the 2D integer array to be deleted.
@param n The number of rows in the array.
The time complexity of the function is O(n^2), as it iterates over all rows and columns in the 2D array.
*/

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

/**
@brief Deletes a dynamically allocated 2D array of doubles.
This function frees the memory allocated to a 2D array of doubles with the given number of rows.
If the matrix pointer is already nullptr, this function does nothing.
@param m A pointer to the 2D array of doubles to be deleted.
@param n The number of rows in the matrix.
*/

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

/**
@brief Tests if a vertex can be visited and adds it to the BFS queue if it can be.
This function checks if a vertex has already been visited and if there is still available
residual capacity on the edge leading to the vertex. If both conditions are met, the vertex
is marked as visited, its path is set to the given edge, and it is added to the BFS queue.
@param q The BFS queue of vertices to visit.
@param e The edge leading to the vertex being visited.
@param w The vertex being visited.
@param residual The residual capacity of the edge leading to the vertex.
@return void
@note This function does not modify the graph itself, only the visited state and path of vertices.
@note The BFS queue must be passed by reference in order to be modified.
@note This function is used internally by the edmondsKarp algorithm.
@complexity O(1)
*/

void Graph::testAndVisit(queue< Vertex*> &q, Edge *e, Vertex *w, double residual) {
    if (! w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

/**
@brief Finds an augmenting path between two vertices in the graph using a breadth-first search algorithm.
The function searches for an augmenting path between two vertices using a breadth-first search algorithm
starting at the source vertex s and stopping when it reaches the target vertex t. If an augmenting path is
found, the function returns true and stores the path in the "path" attribute of the vertices. Otherwise,
it returns false and the "path" attribute of the vertices is set to nullptr.
@param s Pointer to the source vertex.
@param t Pointer to the target vertex.
@return True if an augmenting path was found, false otherwise.
@note This function uses a queue data structure to implement the breadth-first search algorithm, and it
sets the "visited" and "path" attributes of the vertices. The time complexity of the function is O(E),
where E is the number of edges in the graph, because it visits each edge at most twice (once in each direction).
The space complexity of the function is also O(E), because it uses a queue to store the vertices to be visited.
*/

bool Graph::findAugmentingPath(Vertex *s, Vertex *t) {
    for (auto v : vertexSet) {
        v->setVisited(false);
        v->setPath(nullptr);
    }
    s->setVisited(true);
    queue<Vertex *> q;
    q.push(s);
    while (!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();
        for (auto e : v->getAdj()) {
            auto w = e->getDest();
            if (!w->isVisited() && e->getWeight() - e->getFlow() > 0) {
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
        for (auto e : v->getIncoming()) {
            auto w = e->getOrig();
            if (!w->isVisited() && e->getFlow() > 0) {
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
    }
    return t->isVisited();
}

/**
@brief Finds the minimum residual capacity along a path from s to t.
This function takes two vertex pointers, s and t, representing the start and end
vertices of a path, respectively. It then traverses the path backwards from t to s,
calculating the minimum residual capacity along the path as it goes.
@param s Pointer to the source vertex of the path.
@param t Pointer to the target vertex of the path.
@return The minimum residual capacity along the path from s to t.
@pre The vertices s and t must belong to the current graph object.
 */

double Graph::findMinResidualAlongPath(Vertex *s, Vertex *t) {
    auto e = t->getPath();
    double minResidual = e->getWeight() - e->getFlow();
    auto v = e->getOrig();
    while (v != s) {
        e = v->getPath();
        if (e->getWeight() - e->getFlow() < minResidual) { // use edge weight minus current flow
            minResidual = e->getWeight() - e->getFlow(); // use edge weight minus current flow
        }
        v = e->getOrig();
    }
    return minResidual;
}

/**
@brief Test whether a vertex can be visited and pushed to a queue in the context of an algorithm.
@param q A reference to a queue of vertices.
@param e A pointer to the edge connecting the vertices.
@param w A pointer to the destination vertex.
@param residual The residual capacity of the edge.
@return None.
This function checks whether a vertex has not been visited yet and has a positive residual capacity before setting the vertex's visited status, path and pushing it into a queue.
Time complexity: O(1)
*/

void Graph::augmentFlowAlongPath(Vertex *s, Vertex *t, double f) {
    auto v = t;
    while (v != s) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            e->setFlow(e->getFlow() + f); // add f to current flow
        } else {
            e->setFlow(e->getFlow() - f); // subtract f from current flow
        }
        v = e->getOrig();
    }
}

/**
@brief Applies the Edmonds-Karp algorithm to find the maximum flow in the graph from a given source to a given target vertex.
This function applies the Edmonds-Karp algorithm to find the maximum flow in the graph from a given source to a given target vertex.
The algorithm works by iteratively finding augmenting paths from the source to the target and updating the flow along these paths.
The implementation uses breadth-first search to find the augmenting paths.
@param source The name of the source vertex.
@param target The name of the target vertex.
@throws std::logic_error if the source or target vertex is not found in the graph or if the source and target vertices are the same.
@note This function resets the flow values of all edges in the graph to zero before starting the algorithm.
@see findAugmentingPath(Vertex *s, Vertex *t)
@see findMinResidualAlongPath(Vertex *s, Vertex *t)
@see augmentFlowAlongPath(Vertex *s, Vertex *t, double f)
@complexity The time complexity of this algorithm is O(E^2 * V), where E is the number of edges in the graph and V is the number of vertices.
*/

void Graph::edmondsKarp(string source, string target) {
    Vertex *s = findVertex(source);
    Vertex *t = findVertex(target);
    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target vertex");

    for (auto v : vertexSet) {
        for (auto e : v->getAdj()) {
            e->setFlow(0);
        }
    }
    while (findAugmentingPath(s, t)) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}


/**
Dijkstra's algorithm for finding the shortest path between two vertices in the graph.
This function uses Dijkstra's algorithm to calculate the shortest path between a source
and a target vertex in the graph. The result is stored in the path vector, which
contains the vertices of the path in order from the source to the target. The function
assumes that all edges in the graph have non-negative weights.
@param source The source vertex.
@param target The target vertex.
@param path A reference to a vector of vertices that will store the resulting path.
@return void
@complexity O(E*log(V)), where E is the number of edges and V is the number of vertices in the graph.
*/

void Graph::dijkstra(Vertex *source, Vertex *target, vector<Vertex*>& path) {
    for (auto v : vertexSet) {
        v->setDist(INF);
        v->setPath(nullptr);
    }
    source->setDist(0);

    priority_queue<pair<double, Vertex*>, vector<pair<double, Vertex*>>, greater<>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        Vertex *v = pq.top().second;
        pq.pop();

        if (v == target) {
            break;
        }


        if (v->isVisited()) {
            continue;
        }
        v->setVisited(true);

        for (auto e : v->getAdj()) {
            Vertex *w = e->getDest();
            double weight = e->getWeight();

            if (w->getDist() > v->getDist() + weight) {
                w->setDist(v->getDist() + weight);
                w->setPath(e);

                pq.emplace(w->getDist(), w);
            }
        }
    }

    path.clear();
    for (Vertex *v = target; v != nullptr; v = v->getPath() ? v->getPath()->getOrig() : nullptr) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
}

/**
@brief Creates a reduced graph from a given graph, where the weight of edges in a specific line is reduced by a given threshold.
This function takes a Graph object, a string representing a line name, and an integer k, and uses them to create a new Graph
object representing a reduced version of the original graph. The weight of edges in the given line is reduced by k in the new
graph. The reduced graph has the same vertices as the original graph, but potentially different edges and weights.
@param graph A const Graph reference to the original graph object.
@param line A const string reference representing the name of a line in the graph.
@param k An integer representing the threshold for reducing the weight of edges in the given line.
@return A Graph object representing the reduced version of the original graph.
The space complexity is also O(V * E), since the reduced graph may have the same number of vertices and edges as the given graph.
*/

Graph Graph::createReducedGraph(const Graph& graph, const string& line, int k) {
    Graph reducedGraph;

    for (const auto& vertex : graph.getVertexSet()) {
        reducedGraph.addVertex(vertex->getName(), vertex->getDistrict(), vertex->getMunicipality(),
                               vertex->getTownship(), vertex->getLine());
    }

    for (const auto& vertex : graph.getVertexSet()) {
        for (const auto& edge : vertex->getAdj()) {
            Vertex* adjVertex = edge->getDest();
            if (vertex->getLine() == line && adjVertex->getLine() == line) {
                reducedGraph.addEdge(vertex->getName(), adjVertex->getName(), edge->getWeight() - k, edge->getService());
            }
            else {
                reducedGraph.addEdge(vertex->getName(), adjVertex->getName(), edge->getWeight(), edge->getService());
            }
        }
    }

    return reducedGraph;
}



Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}
