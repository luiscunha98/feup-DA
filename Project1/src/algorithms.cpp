//
// Created by Andres Villota on 29/03/2023.
//

#include <map>
#include "algorithms.h"
#include "newGraph.h"

using namespace std;

//T-2.1

/**

@brief Computes the maximum number of trains that can simultaneously travel between two given vertices using the Edmonds-Karp algorithm.

@param g The input graph.

@param sourc The name of the source vertex.

@param dest The name of the destination vertex.

@return A string with the result of the computation.

@brief Computes the pair of vertices with the highest flow between them using the Edmonds-Karp algorithm.

@param g The input graph.

@details The time complexity of this function is O(|V|^2 * |E|), where |V| is the number of vertices in the graph and |E| is the number of edges in the graph.
*/

string Algorithms::T2_1(Graph g, string sourc, string dest) {

    g.edmondsKarp(sourc, dest);

    auto v = g.findVertex(sourc);

    int flow = 0;

    for (const auto e : v->getAdj()){
        flow += e->getFlow();
    }

    return "The maximum number of trains that can simultaneously travel between " + sourc + " and " + dest + " is " + to_string(flow) + " trains";

}

//T-2.2

/**

@brief Finds a district with a given name in a vector of districts.

@param name The name of the district to be found.

@param districts The vector of districts to search.

@return A pointer to the district with the given name, or nullptr if it is not found.

@brief Computes the district with the highest flow of trains using the Edmonds-Karp algorithm.

@param g The input graph.

@details The time complexity of this function is O(|V|^4 * |E|), where |V| is the number of vertices in the graph and |E| is the number of edges in the graph.
*/


void Algorithms::T2_2(Graph& g) {
    double maxFlow = 0;
    pair<Vertex*, Vertex*> maxFlowPair;

    vector<Vertex*> vertices = g.getVertexSet();

    for (auto u : vertices) {
        for (auto v : vertices) {
            if (u != v) {
                g.edmondsKarp(u->getName(), v->getName());

                double flow = 0;
                for (const auto e : u->getAdj()) {
                    flow += e->getFlow();
                }

                if (flow >= maxFlow) {
                    maxFlow = flow;
                    maxFlowPair = {u, v};
                }
            }
        }
    }

    cout << "The pair with the highest flow is: (" << maxFlowPair.first->getName() << ", " << maxFlowPair.second->getName() << ") with a flow of " << maxFlow << endl;
}


//T-2.3

/**
@brief Separates edges in a graph by district and stores them into a map.

This function iterates through each vertex in the given graph and for each adjacent edge, it checks if the destination vertex is in the same district as the current vertex. If the vertices are in the same district, the edge is added to a vector corresponding to the district in a map. The resulting map has keys corresponding to each district and values corresponding to vectors of edges.

@param graph Pointer to the graph object.

@return A map where each key is a district name and each value is a vector of edges

@note The function has a time complexity of O(|V|*|E|) since it needs to iterate through all vertices and adjacent edges to check if they are in the same district.
*/

//Function that separate Edges By District and stores them into a vector.
map<string, vector<Edge*>> Algorithms::separateEdgesByDistrict(Graph* graph) {
    map<string, vector<Edge*>> districtMap;

    for (auto vertex : graph->getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            Vertex* destVertex = edge->getDest();
            if (vertex->getDistrict() == destVertex->getDistrict()) {
                string district = vertex->getDistrict();
                districtMap[district].push_back(edge);
            }
        }
    }

    return districtMap;
}

//Function that calculate the District Flows inside that vector

/**
@brief Calculates the flow for each district based on the edges in the input map.

@param districtMap A map where each key is a district name and each value is a vector of edges.

@return A map where each key is a district name and each value is the total flow in that district.

The time complexity is O(E), where E is the total number of edges in the graph. This is because the function iterates through each vertex in the graph and for each adjacent edge, it checks if the destination vertex is in the same district as the current vertex and adds the edge to a vector corresponding to the district in a map.
*/

map<string, double> Algorithms::calculateDistrictFlows(map<string, vector<Edge*>>& districtMap) {
    map<string, double> districtFlows;

    for (auto& entry : districtMap) {
        string district = entry.first;
        vector<Edge*> edges = entry.second;

        // Calculate the total flow for the current district
        double totalFlow = 0.0;
        for (auto edge : edges) {
            totalFlow += edge->getWeight();
        }

        districtFlows[district] = totalFlow;
    }

    return districtFlows;
}


//Function that separate Edges By Municipality and stores them into a vector.

/**
@brief This function separates edges in a graph by municipality and stores them into a map.
This function iterates through each vertex in the given graph and for each adjacent edge, it checks if the destination vertex is in the same municipality as the current vertex. If the vertices are in the same municipality, the edge is added to a vector corresponding to the municipality in a map. The resulting map has keys corresponding to each municipality and values corresponding to vectors of edges.

@param graph Pointer to the graph object.

@return A map where each key is a municipality name and each value is a vector of edges.

@complexity O(V * E), where V is the number of vertices in the graph and E is the number of edges.
The function iterates through each vertex and its adjacent edges, therefore its time complexity is proportional to the number of vertices and edges in the graph.
*/

map<string, vector<Edge*>> Algorithms::separateEdgesByMunicipality(Graph* graph) {
    map<string, vector<Edge*>> municipalityMap;

    for (auto vertex : graph->getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            Vertex* destVertex = edge->getDest();
            if (vertex->getMunicipality() == destVertex->getMunicipality()) {
                string municipality = vertex->getMunicipality();
                municipalityMap[municipality].push_back(edge);
            }
        }
    }

    return municipalityMap;
}

//Function that calculate the Municipality Flows inside that vector

/**
@brief Calculates the total flow of each municipality from a map of edges separated by municipality.
This function takes a map of edges separated by municipality and calculates the total flow for each municipality by iterating over the edges in each vector of the map. The resulting map has keys corresponding to each municipality and values corresponding to the total flow.

@param municipalityMap A map where each key is a municipality name and each value is a vector of edges.

@return A map where each key is a municipality name and each value is the total flow.

@complexity The time complexity of this function is O(NM) where N is the number of vertices in the graph and M is the number of edges connected to each vertex. The space complexity is also O(NM) due to the use of a map to store the municipality flows.
*/

map<string, double> Algorithms::calculateMunicipalityFlows(map<string, vector<Edge*>>& municipalityMap) {
    map<string, double> municipalityFlows;

    for (auto& entry : municipalityMap) {
        string municipality = entry.first;
        vector<Edge*> edges = entry.second;

        // Calculate the total flow for the current municipality
        double totalFlow = 0.0;
        for (auto edge : edges) {
            totalFlow += edge->getWeight();
        }

        municipalityFlows[municipality] = totalFlow;
    }

    return municipalityFlows;
}

//Function that sorts the vector by flow

/**
@brief Sorts the districts in a graph by their flow and returns the top n districts.
This function separates the edges in a given graph by district and calculates the total flow for each district. It then sorts the districts by their flow in descending order and returns the top n districts with the highest flow.

@param graph Pointer to the graph object.

@param n Number of top districts to return.

@return A vector of strings with the names of the top n districts sorted by flow.

@complexity The time complexity of this function is O(mnlogn), where m is the number of edges in the graph and n is the number of districts. This is because the function calls the separateEdgesByDistrict and calculateDistrictFlows functions, both of which have a time complexity of O(m), and then sorts the resulting map, which has a size of n, using the sort function, which has a time complexity of O(nlogn).
*/

vector<string> Algorithms::T2_3Districts(Graph* graph, int n) {
    // Separate edges by district
    map<string, vector<Edge*>> districtMap = separateEdgesByDistrict(graph);

    // Calculate district flows
    map<string, double> districtFlows = calculateDistrictFlows(districtMap);

    // Sort districts by flow (in descending order)
    vector<pair<string, double>> sortedDistricts(districtFlows.begin(), districtFlows.end());
    sort(sortedDistricts.begin(), sortedDistricts.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second > b.second;
    });

    // Return top four districts
    vector<string> topDistricts;
    for (int i = 0; i < n && i < sortedDistricts.size(); i++) {
        topDistricts.push_back(sortedDistricts[i].first);
    }

    return topDistricts;
}

//Function that sorts the vector by flow

/**
@brief Separates edges in a graph by municipality and stores them into a map.
This function iterates through each vertex in the given graph and for each adjacent edge, it checks if the destination vertex is in the same municipality as the current vertex. If the vertices are in the same municipality, the edge is added to a vector corresponding to the municipality in a map. The resulting map has keys corresponding to each municipality and values corresponding to vectors of edges.
@param graph Pointer to the graph object.

@return A map where each key is a municipality name and each value is a vector of edges.

@complexity O(|V||E|) where |V| is the number of vertices and |E| is the number of edges in the graph.
*/

vector<string> Algorithms::T2_3Municipalities(Graph* graph, int n) {
    // Separate edges by municipality
    map<string, vector<Edge*>> municipalityMap = separateEdgesByMunicipality(graph);

    // Calculate municipality flows
    map<string, double> municipalityFlows = calculateMunicipalityFlows(municipalityMap);

    // Sort municipalities by flow (in descending order)
    vector<pair<string, double>> sortedMunicipalities(municipalityFlows.begin(), municipalityFlows.end());
    sort(sortedMunicipalities.begin(), sortedMunicipalities.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second > b.second;
    });

    // Return top n municipalities
    vector<string> topMunicipalities;
    for (int i = 0; i < n && i < sortedMunicipalities.size(); i++) {
        topMunicipalities.push_back(sortedMunicipalities[i].first);
    }

    return topMunicipalities;
}



//T-2.4

/**

@brief Computes the maximum number of trains that can simultaneously arrive at a given station using the Edmonds-Karp algorithm.

@param g The input graph.

@param station The name of the station to compute the maximum flow of trains.

@details The time complexity of this function is O(|V|^3 * |E|), where |V| is the number of vertices in the graph and |E| is the number of edges in the graph.
*/

void Algorithms::T2_4(Graph &g, const string &station) {
    double maxFlow = 0;

    Vertex *dest = g.findVertex(station);
    if (dest == nullptr) {
        cout << "Station not found in the graph." << endl;
        return;
    }

    vector<Vertex *> vertices = g.getVertexSet();

    for (auto &source : vertices) {
        if (source->getName() != station) {
            g.edmondsKarp(source->getName(), station);
            double flow = 0;

            for (const auto &e : source->getAdj()) {
                if (e->getDest() == dest) {
                    flow += e->getFlow();
                }
            }
            maxFlow += flow;
        }
    }

    cout << "The maximum number of trains that can simultaneously arrive at " << station << " is " << maxFlow << " trains" << endl;
}

//T-3.1

/**

@brief Computes the minimum weight along a given path in a graph.
@param path A vector of vertices representing the path.
@return The minimum weight along the path.
@details The time complexity of this function is O(|E|), where |E| is the number of edges in the graph.
*/

double Algorithms::getFlowAlongPath(const vector<Vertex*>& path) {
    double minWeight = INFINITY;
    for (int i = 0; i < path.size() - 1; i++) {
        Vertex *v = path[i];
        Vertex *w = path[i+1];
        double weight = INFINITY;
        for (auto e : v->getAdj()) {
            if (e->getDest() == w) {
                weight = e->getWeight();
                break;
            }
        }
        if (weight < minWeight) {
            minWeight = weight;
        }
    }
    return minWeight;
}

/**
@brief Calculates the cost of a path in a graph, taking into account the minimum weight and the type of service.
This function takes a vector of vertices representing a path in a graph and a minimum weight, and calculates the
total cost of the path, taking into account the type of service used on each edge. If the service is "STANDARD",
the cost is multiplied by 2, and if the service is "ALFA PENDULAR", the cost is multiplied by 4.
@param path A vector of Vertex pointers representing the path in the graph.
@param minWeight The minimum weight to be considered in the cost calculation.
@return The total cost of the path, taking into account the type of service used on each edge.
The space complexity is O(1), since the function uses only a few local variables to calculate the cost.
*/

double Algorithms::getPathCost(const vector<Vertex*>& path, double minWeight) {
    double cost = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        Vertex *v = path[i];
        Vertex *w = path[i+1];
        double weight = INFINITY;
        string service = "";
        for (auto e : v->getAdj()) {
            if (e->getDest() == w) {
                weight = e->getWeight();
                service = e->getService();
                break;
            }
        }
        if (service == "STANDARD") {
            cost += minWeight * 2;
        } else if (service == "ALFA PENDULAR") {
            cost += minWeight * 4;
        }
    }
    return cost;
}

/**

@brief Executes task T3.1 of the project, which involves printing a given path, its flow, and its cost to the console.
This function takes a vector of Vertex pointers representing a path in a graph, and calculates the flow and cost of
the path. It then prints the path to the console, along with its flow and cost.
@param path A vector of Vertex pointers representing the path in the graph.
The space complexity also depends on the size of the data structures used to store the given path, as well as the results of the flow and cost calculations.
*/

void Algorithms::T3_1(const vector<Vertex*>& path) {
    double minWeight = getFlowAlongPath(path);
    double cost = getPathCost(path, minWeight);

    for (auto v : path) {
        cout << " ("<< v->getName()  <<") " << " -> ";
    }

    cout << "End !" << endl;

    cout << "Flow of the path: " << minWeight << endl;

    cout << "Cost of the path: " << cost << endl;
}

//T-4.1  on main function

/**
@brief Calculates the maximum number of trains that can simultaneously travel between two specific stations in a reduced graph.
This function takes a Graph object representing a reduced graph, as well as two strings representing the source and
destination stations, respectively. It calculates the maximum flow between the source and destination vertices in the
reduced graph using the calculateMaxFlow function, and converts the result to the maximum number of trains that can
simultaneously travel between the stations, assuming a minimum capacity per train. The result is returned as an integer.
@param reducedGraph A reference to a Graph object representing the reduced graph.
@param source A const string reference representing the name of the source station.
@param destination A const string reference representing the name of the destination station.
@return An integer representing the maximum number of trains that can simultaneously travel between the source and destination stations in the reduced graph.
*/

//T-4.2

/**
@brief Executes task T4.2 of the project, which involves creating a reduced graph from a given graph.
This function takes a Graph object, a string representing a line name, and an integer k, and uses them to
create a reduced graph. It then calls the T2_3Districts and T2_3Municipalities functions to find the top
districts and municipalities by flow in the reduced graph. Finally, it prints a report of the results to
the console, which includes the top districts and municipalities by flow.
@param g A Graph object representing the original graph.
@param line A string representing the name of a line in the graph.
@param k An integer representing the threshold for the reduced graph.
The space complexity also depends on the size of the data structures used to store the reduced graph, as well as the results of the T2_3Districts and T2_3Municipalities functions.
*/

void Algorithms::T4_2(Graph g, string line, int k ) {
    Graph r = Graph::createReducedGraph(g, line, k);

    vector<string> topDistricts = Algorithms::T2_3Districts(&r, 10);

    vector<string> topMunicipality = Algorithms::T2_3Municipalities(&r, 10);

    cout << "REPORT:" << endl;

    cout << "Top districts by flow:" << endl;
    for (int i = 0; i < topDistricts.size(); i++) {
        cout << i + 1 << ". " << topDistricts[i] << endl;
    }
    cout << endl;

    cout << "Top Municipality by flow:" << endl;
    for (int i = 0; i < topMunicipality.size(); i++) {
        cout << i + 1 << ". " << topMunicipality[i] << endl;
    }
}