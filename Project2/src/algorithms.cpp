#include "../header/algorithms.h"
#include <iostream>
#include <climits>
#include <cmath>
#include "../header/CSVReader.h"
#include <chrono>
#include <iomanip>
#include <vector>
#include <stack>
using namespace std;

// Backtracking Heuristic for the Toy Graphs
void Algorithms::backtrackingRWG(string &filename) {
    GraphAM graph = GraphAM(0);
    CSVReader::read_RWG(filename,graph);
    int n = graph.getNumNodes();
    vector<bool> v(n);
    vector<int> path;  // Store the path
    for (int i = 0; i < n; i++)
        v[i] = false;
    v[0] = true;
    float min = INT_MAX;

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Find the minimum weight Hamiltonian Cycle and store the path
    graph.tsp(v, 0, n, 1, 0, min, path);

    // Calculate execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();



    // Output the minimum distance and execution time
    cout << "Distance for the PATH exactly above: " << min << endl;

    // Format and output the execution time with 2 decimal places
    cout << "Execution time: " << fixed << setprecision(2) << executionTime << " seconds" << endl << endl;
}
void Algorithms::backtrackingTG(const string& filename) {
    //tourism-> ~0s n=5
    //stadium-> ~2.94 n=11
    //n=20 3 * (20!/11!) = 3 * (20 * 19 * 18 * ... * 2 * 1) / (11 * 10 * 9 * ... * 2 * 1) ~ 12,988,800s. rough estimte
    // Create the graph and read the data
    GraphAM graph = GraphAM(0);
    CSVReader::read_TG(filename, graph);

    // Initialize variables
    int n = graph.getNumNodes();
    vector<bool> v(n);
    vector<int> path;  // Store the path
    for (int i = 0; i < n; i++)
        v[i] = false;
    v[0] = true;
    float min = INT_MAX;

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Find the minimum weight Hamiltonian Cycle and store the path
    graph.tsp(v, 0, n, 1, 0, min, path);

    // Calculate execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();



    // Output the minimum distance and execution time
    cout << "Distance for the PATH exactly above: " << min << endl;

    // Format and output the execution time with 2 decimal places
    cout << "Execution time: " << fixed << setprecision(2) << executionTime << " seconds" << endl << endl;
}


// Backtracking Heuristic for the Real World Graph

void preorderWalk(int parent[],int V, int node,int & last) {
    std::cout << node << " ";  // Process current node
    last = node;
    // Recursively traverse the children of the current node
    for (int child = 0; child < V; ++child) {
        if (parent[child] == node) {
            preorderWalk(parent, V, child,last );
        }
    }
}


int minKey(int key[], int V,bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int V , float **graph, int & ans)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++){
        ans += graph[i][parent[i]];
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
    }

}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(float **graph, int V)
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {

        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, V,mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v]
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    int ans = 0;
    printMST(parent, V, graph, ans);
    int last;
    preorderWalk(parent,V, 0,last);cout  << "0\n";
    ans += graph[last][0];
    cout  <<"total:"<<ans<< "\n";

}

int getMinIndex(float key[], bool mst[],int n) {

    // initialize min and min_index
    int min = std::numeric_limits<int>::max();
    int min_index;

    // iterate through each vertex
    for (int i = 0; i < n; i++) {

        // if vertex hasn't been visited and has a smaller key than min
        if (!mst[i] && key[i] < min) {

            // reassign min and min_index to the values from this node
            min = key[i];
            min_index = i;

        }

    }

    return min_index;

}

void findMST(GraphAM *graphAm) {
    int n = graphAm->getN();
    auto *key = new float [n];
    bool *included = new bool[n];
    int *parent = new int[n];

    for (int i = 0; i < n; i++) {

        // set each key to infinity
        key[i] = std::numeric_limits<::float_t >::max();

        // node node yet included in MST
        included[i] = false;

    }

    // root of MST has distance of 0 and no parent
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {

        // find closes vertex not already in tree
        int k = getMinIndex(key, included,graphAm->getN());

        // set included to true for this vertex
        included[k] = true;

        // examine each unexamined vertex adjacent to most recently added
        for (int j = 0; j < n; j++) {

            // node exists, is unexamined, and graph[k][j] less than previous
            // key for u
            if (graphAm->getAt(k, j) && !included[j] && graphAm->getAt(k, j) < key[j]) {

                // update parent
                parent[j] = k;

                // update key
                key[j] = graphAm->getAt(k, j);

            }
        }
    }
    for (int i = 0; i < n; i++) {

        int j = parent[i];

        if (j != -1) {
            graphAm->addToAdjList(i,j);

        }

    }
}

void findOdds(GraphAM *graphAm) {

    for (int i = 0; i < graphAm->getN(); i++) {

        // if degree of vertex i is odd
        if ((graphAm->getadjSizeAt(i) % 2) != 0) {

            // push vertex to odds, which is a representation of subgraph O
            graphAm->pushToOdd(i);

        }
    }
}

void perfectMatching(GraphAM* graphAm) {
    int closest, length; //int d;
    std::vector<int>::iterator tmp, first;

    // Find nodes with odd degrees in T to get subgraph O
    findOdds(graphAm);

    // for each odd node
    vector<int> odds = graphAm->getOdds();
    while (!odds.empty()) {

        first = odds.begin();
        auto it = odds.begin() + 1;
        auto end = odds.end();
        length = std::numeric_limits<int>::max();
        for (; it != end; ++it) {
            // if this node is closer than the current closest, update closest and length
            if (graphAm->getAt(*first,*it) < length) {
                length = graphAm->getAt(*first,*it);
                closest = *it;
                tmp = it;
            }
        } // two nodes are matched, end of list reached
        graphAm->addToAdjList(*first,closest);
        odds.erase(tmp);
        odds.erase(first);
    }
}

void euler_tour(int start, vector<int> &path,GraphAM *graphAm){
    //Create copy of adj. list
    int n = graphAm->getN();
    vector<int> *tempList = new vector<int>[n];
    for(int i = 0; i < n; i++){
        tempList[i].resize(graphAm->getadjSizeAt(i));
        tempList[i] = graphAm->getadjAt(i);
    }

    stack<int> stack;
    int pos = start;
    path.push_back(start);
    while(!stack.empty() || tempList[pos].size() > 0){
        //Current node has no neighbors
        if(tempList[pos].empty()){
            //add to circuit
            path.push_back(pos);
            //remove last vertex from stack and set it to current
            pos = stack.top();
            stack.pop();
        }
            //If current node has neighbors
        else{
            //Add vertex to stack
            stack.push(pos);
            //Take a neighbor
            int neighbor = tempList[pos].back();
            //Remove edge between neighbor and current vertex
            tempList[pos].pop_back();
            for(int i = 0; i < tempList[neighbor].size(); i++){
                if(tempList[neighbor][i] == pos){
                    tempList[neighbor].erase(tempList[neighbor].begin()+i);
                }
            }
            //Set neighbor as current vertex
            pos = neighbor;
        }
    }
    path.push_back(pos);
}

void make_hamiltonian(vector<int> &path, int &pathCost,GraphAM* graphAm){
    int n = graphAm->getN();

    //remove visited nodes from Euler tour
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    pathCost = 0;

    int root = path.front();
    auto cur = path.begin();
    auto iter = path.begin()+1;
    visited[root] = 1;

    //iterate through circuit
    bool addMore = true;
    while(iter != path.end()){
        if(!visited[*iter]){
            pathCost += graphAm->getAt(*cur,*iter);
            cur = iter;
            visited[*cur] = 1;
            iter = cur + 1;
        }
        else{
            iter = path.erase(iter);
        }
    }
    //Add distance to root
    pathCost += graphAm->getAt(*cur,*iter);

}

int findBestPath(int start,GraphAM* graphAm){
    vector<int> path;
    euler_tour(start, path,graphAm);
    int length;

    make_hamiltonian(path, length,graphAm);
    return length;
}

void printResult(GraphAM *graphAm){
    for (int & it : graphAm->getCircuit()) {
        cout << it << endl;
    }
    cout << *graphAm->getCircuit().begin() << endl;
};

void printPath(GraphAM( *graphAm)){
    cout << endl;
    for (auto it = graphAm->getCircuit().begin(); it != graphAm->getCircuit().end()-1; ++it) {
        cout << *it << " to " << *(it+1) << " ";
        cout << graphAm->getAdjacencyMatrix()[*it][*(it+1)] << endl;
    }
    cout << *(graphAm->getCircuit().end()-1) << " to " << graphAm->getCircuit().front()<< " ";
    cout << graphAm->getAdjacencyMatrix()[*(graphAm->getCircuit().end()-1)][graphAm->getCircuit().front()] << endl;
    cout << "\nLength: " << graphAm->getPathLength()<< endl << endl;
};

void Algorithms::triangularapproximationTG(const string& filename) {
    // Create the graph and read the data
    auto* graph = new GraphAM(0);
    CSVReader::read_TG(filename, *graph);

    int numNodes = graph->getNumNodes();
    primMST(graph->getAdjacencyMatrix(),numNodes);

}
void Algorithms::triangularapproximationRWG(const string& filename) {
    // Create the graph and read the data
    auto* graph = new GraphAM(0);
    CSVReader::read_RWG(const_cast<string &>(filename), *graph);

    int numNodes = graph->getNumNodes();
    primMST(graph->getAdjacencyMatrix(),numNodes);

}



void Algorithms::nearestNeighborTSP(const string& filename) {
    // Create the graph and read the data
    GraphAM graph = GraphAM(0);
    CSVReader::read_TG(filename, graph);

    int numNodes = graph.getNumNodes();

    // Initialize variables
    vector<bool> visited(numNodes, false);
    vector<int> tour;
    int startNode = 0;
    visited[startNode] = true;
    tour.push_back(startNode);

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Construct the approximate tour using the nearest neighbor heuristic
    int currentNode = startNode;
    while (tour.size() < numNodes) {
        int nextNode = -1;
        float minDistance = INT_MAX;

        // Find the nearest unvisited neighbor with the minimum distance
        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (!visited[neighbor]) {
                float distance = graph.getWeight(currentNode, neighbor);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextNode = neighbor;
                }
            }
        }

        // Mark the next node as visited and add it to the tour
        visited[nextNode] = true;
        tour.push_back(nextNode);
        currentNode = nextNode;
    }

    // Add the start node to complete the tour
    tour.push_back(startNode);

    // Calculate the total distance of the tour
    float totalDistance = 0.0;
    for (int i = 0; i < numNodes - 1; ++i) {
        int currentNode = tour[i];
        int nextNode = tour[i + 1];
        totalDistance += graph.getWeight(currentNode, nextNode);
    }
    totalDistance += graph.getWeight(*(tour.end()-2),startNode );
    // Measure end execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    // Output the approximate tour, total distance, and execution time
    cout << "Nearest Neighbor Path: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;
    cout << "Distance of the Path: " << totalDistance << endl;
    cout << "Execution Time: " << fixed << setprecision(2) << executionTime << " seconds" << endl;
}

// Helper function to calculate the difference in distance after reversing a segment in the tour
float getDistanceDiff(const vector<int>& tour, int i, int j, const GraphAM& graph) {
    int node1 = tour[i];
    int node2 = tour[j];
    int prevNode1 = tour[i - 1];
    int nextNode1 = tour[i + 1];
    int prevNode2 = tour[j - 1];
    int nextNode2 = (j + 1 < tour.size()) ? tour[j + 1] : tour[0];

    float distanceDiff = 0.0;
    distanceDiff += graph.getWeight(prevNode1, node2);
    distanceDiff += graph.getWeight(node1, nextNode2);
    distanceDiff -= graph.getWeight(prevNode1, node1);
    distanceDiff -= graph.getWeight(node2, nextNode2);

    return distanceDiff;
}

// Helper function to reverse a segment in the tour
void reverseSegment(vector<int>& tour, int i, int j) {
    while (i < j) {
        swap(tour[i], tour[j]);
        i++;
        j--;
    }
}

// Helper function to calculate the total distance of the tour
float calculateTourDistance(const vector<int>& tour, const GraphAM& graph) {
    int numNodes = tour.size();
    float totalDistance = 0.0;
    for (int i = 0; i < numNodes - 1; ++i) {
        int currentNode = tour[i];
        int nextNode = tour[i + 1];
        totalDistance += graph.getWeight(currentNode, nextNode);
    }
    totalDistance += graph.getWeight(tour[numNodes - 1], tour[0]);
    return totalDistance;
}



void Algorithms::twoOptTSP(const string& filename) {
    // Create the graph and read the data
    GraphAM graph = GraphAM(0);
    CSVReader::read_TG(filename, graph);

    int numNodes = graph.getNumNodes();

    // Initialize the initial tour as a simple path
    vector<int> tour(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        tour[i] = i;
    }

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Perform the two-opt optimization
    bool improvement = true;
    while (improvement) {
        improvement = false;
        for (int i = 1; i < numNodes - 2; ++i) {
            for (int j = i + 1; j < numNodes - 1; ++j) {
                float distanceDiff = getDistanceDiff(tour, i, j, graph);
                if (distanceDiff < 0) {
                    reverseSegment(tour, i, j);
                    improvement = true;
                }
            }
        }
    }

    // Add the start node at the end to complete the tour
    tour.push_back(0);

    // Calculate the total distance of the optimized tour
    float totalDistance = calculateTourDistance(tour, graph);

    // Measure end execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    // Output the optimized tour, total distance, and execution time
    cout << "Two-Optimized Path: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;
    cout << "Distance of the Path: " << totalDistance << endl;
    cout << "Execution Time: " << fixed << setprecision(2) << executionTime << " seconds" << endl;
}

void Algorithms::christofides(string& file) {
    GraphAM graphAm=GraphAM(0);
    //CSVReader::read_RWG(file,&graphAm);
    if(file[8]=='R'){
        CSVReader::read_RWG(file,graphAm);
    }
    else CSVReader::read_TG(file,graphAm);
    findMST(&graphAm);
    perfectMatching(&graphAm);
    int best = INT_MAX;
    int bestIndex;
    int tsp_size = graphAm.getN();
    for (long t = 0; t < tsp_size; t++) {
        int result = findBestPath(0,&graphAm);
        graphAm.setPathValLongInt(t,0,t);
        graphAm.setPathValLongInt(t,2,result);

        if (graphAm.getPathValAt(t,1) < best) {
            bestIndex = graphAm.getPathValAt(t,0);
            best = graphAm.getPathValAt(t,1);
        }
    }
    euler_tour(bestIndex, graphAm.getCircuit(),&graphAm);
    make_hamiltonian(graphAm.getCircuit(),graphAm.getPathLength(),&graphAm);
    printResult(&graphAm);
    printPath(&graphAm);

}






