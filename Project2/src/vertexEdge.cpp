#include "../header/vertexEdge.h"

using namespace std;

/************************* Vertex  **************************/

Vertex::Vertex( double lg , double lat):  lg(lg), lat(lat){}



double Vertex::getLG() const{
    return this -> lg;
}

double Vertex::getLAT() const{
    return this -> lat;
}


void Vertex::setLg(double lg) {
    Vertex::lg = lg;
}

void Vertex::setLat(double lat) {
    Vertex::lat = lat;
}


