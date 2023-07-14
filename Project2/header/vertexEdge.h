#ifndef DA1_VERTEXEDGE_H
#define DA1_VERTEXEDGE_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

/**
 * @brief Class representing a vertex in a graph.
 */
class Vertex {
public:
    /**
     * @brief Constructs a new Vertex object.
     * @param lg The longitude of the vertex.
     * @param lat The latitude of the vertex.
     */
    Vertex( double lg, double lat);


    double getLG() const;
    double getLAT() const;


    void setLg(double lg);

    void setLat(double lat);


protected:             ///< The ID of the vertex.
    double lg;              ///< The longitude of the vertex.
    double lat;             ///< The latitude of the vertex.
    //vector<Edge> adj;       ///< The outgoing edges from the vertex.
    //bool visited = false;   ///< Flag indicating whether the vertex has been visited.
};

#endif //DA1_VERTEXEDGE_H
