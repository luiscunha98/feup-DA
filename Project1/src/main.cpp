#include <iostream>
#include <map>

#include "newGraph.h"
#include "utils.h"
#include "algorithms.h"

using namespace std;

int main() {

    int op, op2;
    Graph g = Utils::readGraph();

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                        Railway Network Management                      |" << endl;
    cout << "|                                Main Menu                               |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Basic Service Metrics                                       |" << endl;
    cout << "|  Option 2: Operation Cost Optimization                                 |" << endl;
    cout << "|  Option 3: Reliability and Sensitivity to Line Failures                |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    cout << "Choose an Option between 1 and 3:" << endl;
    cin >> op;


    if (op == 1) {

        cout << "+------------------------------------------------------------------------+" << endl;
        cout << "|                        Railway Network Management                      |" << endl;
        cout << "|                        Basic Service Metrics Menu                      |" << endl;
        cout << "+------------------------------------------------------------------------+" << endl;
        cout << "|                                                                        |" << endl;
        cout << "|  Option 1: Maximum number of trains between two stations               |" << endl;
        cout << "|                                                                        |" << endl;
        cout << "|  Option 2: Stations which requires the most trains                     |" << endl;
        cout << "|                                                                        |" << endl;
        cout << "|  Option 3: Top-k municipalities and districts                          |" << endl;
        cout << "|                                                                        |" << endl;
        cout << "|  Option 4: Maximum number of trains arriving at a station              |" << endl;
        cout << "|                                                                        |" << endl;
        cout << "+------------------------------------------------------------------------+" << endl;

        cout << "Choose an Option between 1 and 4:" << endl;
        cin >> op2;

        if (op2 == 1) {

            string source, dest;
            cout << "Insert initial station:" << endl;
            cin.ignore();
            getline(cin, source);

            cout << "Insert final station:" << endl;
            getline(cin, dest);

            source = Utils::replaceSpecialChars(source);
            dest = Utils::replaceSpecialChars(dest);

            string ans = Algorithms::T2_1(g, source, dest);

            cout << ans << endl;



        } else if (op2 == 2) {
            Algorithms::T2_2(g);

        } else if (op2 == 3) {

            int n;

            cout << "Top=?" << endl;
            cin >> n;

            vector<string> topDistricts = Algorithms::T2_3Districts(&g, n );

            vector<string> topMunicipality = Algorithms::T2_3Municipalities(&g, n );

            cout << "Top districts by flow:" << endl;
            for (int i = 0; i < topDistricts.size(); i++) {
                cout << i + 1 << ". " << topDistricts[i] << endl;
            }
            cout << endl;

            cout << "Top Municipality by flow:" << endl;
            for (int i = 0; i < topMunicipality.size(); i++) {
                cout << i + 1 << ". " << topMunicipality[i] << endl;
            }


        } else if (op2 == 4) {

            string station;
            cout << "Insert station:" << endl;
            cin.ignore();
            getline(cin, station);

            station = Utils::replaceSpecialChars(station);

            Algorithms::T2_4(g, station);

        } else {
            cout << "Invalid Digit!" << endl;
            return 1;
        }
    }
    else if(op == 2){

        cout << "+------------------------------------------------------------------------+" << endl;
        cout << "|                        Railway Network Management                      |" << endl;
        cout << "|                        Operation Cost Optimization                     |" << endl;
        cout << "+------------------------------------------------------------------------+" << endl;
        cout << "|                                                                        |" << endl;
        cout << "|    Maximum amount of trains that can simultaneously travel between     |" << endl;
        cout << "|        two specific stations with minimum cost for the company.        |" << endl;
        cout << "|                                                                        |" << endl;
        cout << "+------------------------------------------------------------------------+" << endl;

        string source, dest;
        cout << "Insert initial station:" << endl;
        cin >> source;

        cout << "Insert final station:" << endl;
        cin >> dest;

        source = Utils::replaceSpecialChars(source);
        dest = Utils::replaceSpecialChars(dest);

        vector<Vertex*> path;

        Vertex *s = g.findVertex(source);
        Vertex *t = g.findVertex(dest);


        g.dijkstra(s, t, path);

        Algorithms::T3_1(path);


    }
    else if(op == 3) {
        cout << "+---------------------------------------------------------------------------------------+" << endl;
        cout << "|                                Railway Network Management                             |" << endl;
        cout << "|                       Reliability and Sensitivity to Line Failures                    |" << endl;
        cout << "+---------------------------------------------------------------------------------------+" << endl;
        cout << "|                                                                                       |" << endl;
        cout << "|  Option 1: Maximum number of trains that can simultaneously travel between            |" << endl;
        cout << "|             two specific stations in a network of reduced connectivity.               |" << endl;
        cout << "|                                                                                       |" << endl;
        cout << "|  Option 2: Report on the stations that are the most affected by each segment failure. |" << endl;
        cout << "|                                                                                       |" << endl;
        cout << "+---------------------------------------------------------------------------------------+" << endl;

        cout << "Choose an Option between 1 and 2:" << endl;
        cin >> op2;

        if (op2 == 1) {
            int k;
            string line;
            string source;
            string dest;

            cout << "What is the line affected:" << endl;
            cin.ignore();
            getline(cin, line);

            line = Utils::replaceSpecialChars(line);

            cout << "How many trains affected:" << endl;
            cin >> k;

            Graph r = Graph::createReducedGraph(g, line, k);

            cout << "Insert initial station:" << endl;
            cin.ignore();
            getline(cin, source);

            cout << "Insert final station:" << endl;
            getline(cin, dest);

            source = Utils::replaceSpecialChars(source);
            dest = Utils::replaceSpecialChars(dest);


            string ans = Algorithms::T2_1(r, source, dest);

            cout << ans << endl;


        } else if (op2 == 2) {
            int k;
            string line;

            cout << "What is the line affected:" << endl;
            cin.ignore();
            getline(cin, line);

            line = Utils::replaceSpecialChars(line);

            cout << "How many trains affected:" << endl;
            cin >> k;

            Algorithms::T4_2(g,line, k);


        } else {
            cout << "Invalid Digit!" << endl;
            return 1;
        }
    }
    else {
        cout << "Invalid Digit!" << endl;
        return 1;
    }

    return 0;
}




