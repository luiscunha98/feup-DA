
#include "../header/CSVReader.h"
#include "../header/vertexEdge.h"
#include <cmath>
CSVReader::CSVReader()= default;;

void CSVReader:: read_TG(const string& fileString, GraphAM &graph) {
    ifstream file(fileString);
    string line;
    if(fileString[8]!='E'){
        getline(file, line);// Skip the header line, but extra dnt have header
    }

    unordered_set<int> nodes;
    int source, destination;
    float distance;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');

        source = stoi(token);

        getline(ss, token, ',');

        destination = stoi(token);

        getline(ss, token, ',');

        distance = stof(token);

        nodes.insert(source);
        nodes.insert(destination);
    }

    int numNodes = nodes.size();
    graph = *(new GraphAM(numNodes));

    file.clear();
    file.seekg(0);  // Reset file pointer to read again from the beginning

    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        source = stoi(token);

        getline(ss, token, ',');
        destination = stoi(token);

        getline(ss, token, ',');
        distance = stof(token);

        graph.addEdge(source, destination, distance);
    }
}
vector<vector<int>> readEdges(const string& filename) {
    ifstream file(filename);
    vector<vector<int>> edges;

    if (file) {
        string line;
        getline(file, line); // Skip the header line

        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            vector<int> edge;

            while (getline(ss, cell, ',')) {
                edge.push_back(stoi(cell));
            }

            edges.push_back(edge);
        }

        file.close();
    }

    return edges;
}

// Function to read the nodes from the CSV file
vector<Vertex> readNodes(const string& filename) {
    ifstream file(filename);
    vector<Vertex> nodes;

    if (file) {
        string line;
        getline(file, line); // Skip the header line

        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            Vertex node = Vertex(0,0);

            getline(ss, cell, ','); // Skip the ID
            getline(ss, cell, ',');
            node.setLat(stod(cell));
            getline(ss, cell, ',');
            node.setLg(stod(cell));
            nodes.push_back(node);
        }

        file.close();
    }

    return nodes;
}

// Function to calculate the Haversine distance between two coordinates
static double calculateDistance(double lat1, double lon1,
                        double lat2, double lon2)
{
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c * 1000;
}
/*double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    constexpr double radius = 6371.0; // Earth's radius in kilometers

    double dlat = (lat2 - lat1) * M_PI / 180.0;
    double dlon = (lon2 - lon1) * M_PI / 180.0;

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return radius * c;
}*/

void CSVReader::read_RWG(string &file, GraphAM& graph) {
    vector<vector<int>> edges = readEdges(file+"edges.csv");
    vector<Vertex> nodes = readNodes(file+"nodes.csv");

    // Determine the number of nodes
    int numNodes = nodes.size();

    cout<<"num nodes"<<numNodes<<endl;
    // Construct the graph
    graph = *(new GraphAM(numNodes));
    // Add edges from the "edges.csv" file
    for (const auto& edge : edges) {
        int origin = edge[0];
        int destination = edge[1];
        int distance = edge[2];
        graph.addEdge(origin, destination, distance);
    }
    //fll matrix

    for(int i = 0; i < numNodes; i++){
        for(int j = i + 1; j < numNodes; j++){
            if(graph.getAt(i,j)!=0)continue;
            double distance = calculateDistance(nodes[i].getLAT(),nodes[i].getLG(),nodes[j].getLAT(),nodes[j].getLG());
            graph.addEdge(j, i, distance);
        }
    }
}


