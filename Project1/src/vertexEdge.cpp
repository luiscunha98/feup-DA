#include "vertexEdge.h"

using namespace std;

/************************* Vertex  **************************/

Vertex::Vertex(string name, string district, string municipality, string township, string line): name(name), district(district), municipality(municipality), township(township), line(line) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */

/**
Adds a new edge to this vertex's adjacency list and the destination vertex's incoming list.
@param d The destination vertex of the new edge.
@param w The weight of the new edge.
@param service The service of the new edge.
@return A pointer to the newly created edge.
@complexity O(1)
*/

Edge * Vertex::addEdge(Vertex *d, double w, string service) {
    auto newEdge = new Edge(this, d, w, service);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */

/**
@brief Remove edge to a vertex with the given name.
@param destName Name of the destination vertex.
@return true if the edge was successfully removed, false otherwise.
@brief Complexity of the function is O(|E|)
*/

bool Vertex::removeEdge(string destName) {
    bool removedEdge = false;
    auto it = adj.begin();
    while (it != adj.end()) {
        Edge *edge = *it;
        Vertex *dest = edge->getDest();
        if (dest->getName() == destName) {
            it = adj.erase(it);
            // Also remove the corresponding edge from the incoming list
            auto it2 = dest->incoming.begin();
            while (it2 != dest->incoming.end()) {
                if ((*it2)->getOrig()->getName() == name) {
                    it2 = dest->incoming.erase(it2);
                }
                else {
                    it2++;
                }
            }
            delete edge;
            removedEdge = true; // allows for multiple edges to connect the same pair of vertices (multigraph)
        }
        else {
            it++;
        }
    }
    return removedEdge;
}


std::string Vertex::getName() const{
    return this -> name;
}

std::string Vertex::getDistrict() const {
    return this -> district;
}

std::string Vertex::getMunicipality() const{
    return this -> municipality;
}

std::string Vertex::getTownship() const{
    return this -> township;
}

std::string Vertex::getLine() const{
    return this -> line;
}

std::vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}

double Vertex::getDist() const {
    return this->dist;
}

Edge *Vertex::getPath() const {
    return this->path;
}

std::vector<Edge *> Vertex::getIncoming() const {
    return this->incoming;
}



void Vertex::setName(string name) {
    this->name = name;
}

void Vertex::setDistrict(string district) {
    this-> district = district;
}

void Vertex::setMunicipality(string municipality) {
    this-> municipality = municipality;
}

void Vertex::setTownship(string township) {
    this->township = township;
}

void Vertex::setLine(string line) {
    this->line = line;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}


void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setPath(Edge *path) {
    this->path = path;
}

/********************** Edge  ****************************/

Edge::Edge(Vertex *orig, Vertex *dest, double w, string service): orig(orig), dest(dest), weight(w), service(service) {}

Vertex * Edge::getDest() const {
    return this->dest;
}

string Edge::getService() const {
    return this-> service;
}

double Edge::getWeight() const {
    return this->weight;
}

double Edge::getFlow() const {
    return this->flow;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}

Edge *Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}


void Edge::setSelected(bool selected) {
    this->selected = selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}

void Edge::setWeight(double w) {
    this->weight= w;
}

void Edge::setFlow(double flow) {
    this->flow = flow;
}
