#ifndef DA1_VERTEXEDGE_H
#define DA1_VERTEXEDGE_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    Vertex(string name, string district, string municipality, string township, string line);

    string getName() const;
    string getDistrict() const;
    string getMunicipality() const;
    string getTownship() const;
    string getLine() const;

    vector<Edge *> getAdj() const;
    bool isVisited() const;
    double getDist() const;
    Edge *getPath() const;
    vector<Edge *> getIncoming() const;


    void setName(string name);
    void setDistrict(string district);
    void setMunicipality(string municipality);
    void setTownship(string township);
    void setLine(string line);

    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Edge *path);
    Edge * addEdge(Vertex *dest, double w, string service);
    bool removeEdge(string destName);

    /**friend class MutablePriorityQueue<Vertex>;**/
protected:

    string name;
    string district;
    string municipality;
    string township;
    string line;
    vector<Edge *> adj;  // outgoing edges


    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;

    vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w, string service);

    Vertex * getOrig() const;
    Vertex * getDest() const;
    string getService() const;
    double getWeight() const;
    double getFlow() const;
    bool isSelected() const;
    Edge *getReverse() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setWeight(double w);
    void setFlow (double flow);
protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity
    string service;

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    double flow;

};

#endif //DA1_VERTEXEDGE_H
