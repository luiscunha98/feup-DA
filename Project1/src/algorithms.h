//
// Created by Andres Villota on 29/03/2023.
//

#ifndef DA1_ALGORITHMS_H
#define DA1_ALGORITHMS_H

#include "newGraph.h"

using namespace std;

class Algorithms{

public:
    static string T2_1(Graph g, string sourc, string dest);
    static void T2_2(Graph& g);
    static vector<string> T2_3Districts(Graph* graph, int n);
    static vector<string> T2_3Municipalities(Graph* graph, int n);
    static void T2_4(Graph &g, const string &station);
    static void T3_1(const vector<Vertex*>& path);
    static void T4_1(Graph g, string line, int k, string source, string dest );
    static void T4_2(Graph g, string line, int k );

    //Auxiliar Functions
    static double getFlowAlongPath(const vector<Vertex*>& path);
    static double getPathCost(const vector<Vertex*>& path, double minWeight);
    static map<string, vector<Edge*>> separateEdgesByDistrict(Graph* g);
    static map<string, double> calculateDistrictFlows(map<string, vector<Edge*>>& districtMap);
    static map<string, vector<Edge*>> separateEdgesByMunicipality(Graph* graph);
    static map<string, double> calculateMunicipalityFlows(map<string, vector<Edge*>>& municipalityMap);

};


#endif //DA1_ALGORITHMS_H
