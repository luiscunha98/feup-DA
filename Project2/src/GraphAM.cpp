//
// Created by nesma on 26/05/2023.
//
#include <bits/stdc++.h>
#include "../header/GraphAM.h"
using namespace std;

GraphAM::GraphAM(int nodes) : numNodes(nodes), adjacencyMatrix(new float*[nodes]) {
    n=nodes;
    for(int i = 0; i < n; i++){
        adjacencyMatrix[i] = new float[n];
        for(int j = 0; j < n; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }
    //new int *[n];


    path_vals = new int*[n];
    for(int i = 0; i < n; i++){
        path_vals[i] = new int[n];
    }

    adjlist = new vector<int>[n];

}


int GraphAM::getNumNodes() const {
    return numNodes;
}

float** GraphAM::getAdjacencyMatrix() const {
    return adjacencyMatrix;
}

/*void GraphAM::setAdjacencyMatrix(float **adjacencyMatrix) {
    GraphAM::adjacencyMatrix = adjacencyMatrix;
}*/

void GraphAM::addEdge(int src, int dest, float dist) {
    adjacencyMatrix[src][dest] = dist;
    adjacencyMatrix[dest][src] = dist;
}

int GraphAM::getN() const {
    return n;
}

int &GraphAM::getPathLength()  {
    return pathLength;
}

vector<int> &GraphAM::getCircuit()  {
    return circuit;
}

// Function to find the minimum weight Hamiltonian Cycle
void GraphAM::tsp(vector<bool>& v, int currPos, int n, int count, float cost, float& minDistance, vector<int>& path) {
    // If last node is reached and there is a link to the starting node,
    // update the minimum distance and store the path
    //cout<<"here\n";
    path.push_back(currPos);
    if (count == n && adjacencyMatrix[currPos][0]) {
        float totalDistance = cost + adjacencyMatrix[currPos][0];
        path.push_back(0);
        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            // Output the path
            cout << "Path: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;


        }
        path.pop_back();
        return;
    }

    // BACKTRACKING STEP
    // Loop to traverse the adjacency matrix of currPos node and increase the count
    // by 1 and cost by adjacencyMatrix[currPos][i] value
    for (int i = 0; i < n; i++) {
        if (!v[i] && adjacencyMatrix[currPos][i]) {
            // Mark as visited
            v[i] = true;
            tsp(v, i, n, count + 1, cost + adjacencyMatrix[currPos][i], minDistance, path);
            path.pop_back();
            // Mark the current node as unvisited
            v[i] = false;
        }
    }
}



float GraphAM::getWeight(int node1, int node2) const {
    return adjacencyMatrix[node1][node2];
}

float GraphAM::getAt(int x, int y) {

    return adjacencyMatrix[x][y];
}

void GraphAM::addToAdjList(int i,int j) {
    adjlist[i].push_back(j);
    adjlist[j].push_back(i);
}

int GraphAM::getadjSizeAt(int i) {
    return adjlist[i].size();
}
vector<int> GraphAM::getadjAt(int i) {
    return adjlist[i];
}
void GraphAM::pushToOdd(int i) {
    odds.push_back(i);
}

const vector<int> &GraphAM::getOdds() const {
    return odds;
}

void GraphAM::setPathValLongInt(long i, int j,float value) {
    path_vals[i][j]=value;
}

int GraphAM::getPathValAt(int i, int j) {
    return path_vals[i][j];
}

GraphAM::~GraphAM() {
    for (int i = 0; i < n; i++) {
        delete[] adjacencyMatrix[i];
        delete[] path_vals[i];
    }
    delete[] path_vals;
    delete[] adjacencyMatrix;
    delete[] adjlist;
}

