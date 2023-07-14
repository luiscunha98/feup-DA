#include <iostream>
#include <climits>
#include "../header/menu.h"
#include "../header/CSVReader.h"
#include "../header/algorithms.h"

using namespace  std;

// Main Menu

void mainMenu() {
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|        Routing Algorithm for Ocean Shipping and Urban Deliveries       |" << endl;
    cout << "|                                Main Menu                               |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Backtracking Heuristic                                      |" << endl;
    cout << "|  Option 2: Triangular Approximation Heuristic(Christofise)             |" << endl;
    cout << "|  Option 3: Other Heuristics                                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 4: About                                                       |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 4:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                cout << endl << "Thank you for using our Program!" << endl;
                exit(0);
            case 1:
                Menu1();
                break;
            case 2:
                Menu2();
                break;
            case 3:
                Menu3();
                break;
            case 4:
                Menu4();
                break;

            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}


//BackTracking Menu

void Menu1(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                            Reading the Data                            |" << endl;
    cout << "|                         Backtracking Heuristic                         |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Real-Word Graphs                                            |" << endl;
    cout << "|  Option 2: Toy Graphs                                                  |" << endl;
    cout << "|  Option 3: Extra Graphs                                                |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
            case 1:
                Menu11();
                break;
            case 2:
                Menu12();
                break;
            case 3:
                Menu133();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

// Backtracking Heuristic Extra Graphs

void Menu133(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Extra Graphs                   |" << endl;
    cout << "|                          Backtracking Heuristic                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Edges 25                                                    |" << endl;
    cout << "|  Option 2: Edges 50                                                    |" << endl;
    cout << "|  Option 3: Edges 75                                                    |" << endl;
    cout << "|  Option 4: Edges 100                                                   |" << endl;
    cout << "|  Option 5: Edges 200                                                   |" << endl;
    cout << "|  Option 6: Edges 300                                                   |" << endl;
    cout << "|  Option 7: Edges 400                                                   |" << endl;
    cout << "|  Option 8: Edges 500                                                   |" << endl;
    cout << "|  Option 9: Edges 600                                                   |" << endl;
    cout << "|  Option 10: Edges 700                                                  |" << endl;
    cout << "|  Option 11: Edges 800                                                  |" << endl;
    cout << "|  Option 12: Edges 900                                                  |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 12:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/EG/edges_25.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/EG/edges_50.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/EG/edges_75.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 4:
            {
                string filename = "../data/EG/edges_100.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 5:
            {
                string filename = "../data/EG/edges_200.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 6:
            {
                string filename = "../data/EG/edges_300.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 7:
            {
                string filename = "../data/EG/edges_400.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 8:
            {
                string filename = "../data/EG/edges_500.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 9:
            {
                string filename = "../data/EG/edges_600.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 10:
            {
                string filename = "../data/EG/edges_700.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 11:
            {
                string filename = "../data/EG/edges_800.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 12:
            {
                string filename = "../data/EG/edges_900.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

//Backtracking Heuristic Real World Graphs

void Menu11(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                    Reading the Data - Real-World Graphs                |" << endl;
    cout << "|                          Backtracking Heuristic                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: GraphAM 1 (1k Nodes, 500 Edges)                             |" << endl;
    cout << "|  Option 2: GraphAM 2 (5k Nodes, 3M  Edges)                             |" << endl;
    cout << "|  Option 3: GraphAM 3 (10K Nodes, 10M Edges)                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/RWG/graph1/edges.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 2:{
                string filename = "../data/RWG/graph2/edges.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 3:
            {

                string filename = "../data/RWG/graphMade2/";
                Algorithms::backtrackingRWG(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

//Backtracking Heuristic Toy Graphs

void Menu12(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Toy Graphs                     |" << endl;
    cout << "|                          Backtracking Heuristic                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Shipping                                                    |" << endl;
    cout << "|  Option 2: Stadiums                                                    |" << endl;
    cout << "|  Option 3: Tourism                                                     |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1: {
                string filename = "../data/TG/shipping.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 2:{
                string filename = "../data/TG/stadiums.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 3:{
                string filename = "../data/TG/tourism.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }

}

//Triangular Approximation Menu

void Menu2(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                            Reading the Data                            |" << endl;
    cout << "|                    Triangular Approximation Heuristic                  |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Real-Word Graphs                                            |" << endl;
    cout << "|  Option 2: Toy Graphs                                                  |" << endl;
    cout << "|  Option 3: Extra Graphs                                                |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
            case 1:
                Menu21();
                break;
            case 2:
                Menu22();
                break;
            case 3:
                Menu33();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

// Triangular Approximation Heuristic Extra Graphs

void Menu33(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Extra Graphs                   |" << endl;
    cout << "|                    Triangular Approximation Heuristic                  |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Edges 25                                                    |" << endl;
    cout << "|  Option 2: Edges 50                                                    |" << endl;
    cout << "|  Option 3: Edges 75                                                    |" << endl;
    cout << "|  Option 4: Edges 100                                                   |" << endl;
    cout << "|  Option 5: Edges 200                                                   |" << endl;
    cout << "|  Option 6: Edges 300                                                   |" << endl;
    cout << "|  Option 7: Edges 400                                                   |" << endl;
    cout << "|  Option 8: Edges 500                                                   |" << endl;
    cout << "|  Option 9: Edges 600                                                   |" << endl;
    cout << "|  Option 10: Edges 700                                                  |" << endl;
    cout << "|  Option 11: Edges 800                                                  |" << endl;
    cout << "|  Option 12: Edges 900                                                  |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 12:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/EG/edges_25.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/EG/edges_50.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/EG/edges_75.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 4:
            {
                string filename = "../data/EG/edges_100.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 5:
            {
                string filename = "../data/EG/edges_200.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 6:
            {
                string filename = "../data/EG/edges_300.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 7:
            {
                string filename = "../data/EG/edges_400.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 8:
            {
                string filename = "../data/EG/edges_500.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 9:
            {
                string filename = "../data/EG/edges_600.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 10:
            {
                string filename = "../data/EG/edges_700.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 11:
            {
                string filename = "../data/EG/edges_800.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 12:
            {
                string filename = "../data/EG/edges_900.csv";
                Algorithms::christofides(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

//Triangular Approximation Real World Graphs

void Menu21(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                    Reading the Data - Real-World Graphs                |" << endl;
    cout << "|                     Triangular Approximation Heuristic                 |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: GraphAM 1 (1k Nodes, 500 Edges)                             |" << endl;
    cout << "|  Option 2: GraphAM 2 (5k Nodes, 3M  Edges)                             |" << endl;
    cout << "|  Option 3: GraphAM 3 (10K Nodes, 10M Edges)                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/RWG/graph1/";
                Algorithms::christofides(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/RWG/graph2/";
                Algorithms::christofides(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/RWG/graph3/";
                Algorithms::christofides(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

// Triangular Approximation Toy Graphs

void Menu22(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Toy Graphs                     |" << endl;
    cout << "|                   Triangular Approximation Heuristic                   |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Shipping                                                    |" << endl;
    cout << "|  Option 2: Stadiums                                                    |" << endl;
    cout << "|  Option 3: Tourism                                                     |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/TG/shipping.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/TG/stadiums.csv";
                Algorithms::christofides(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/TG/tourism.csv";
                Algorithms::christofides(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

//Other Heuristics Menu

void Menu3(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                            Other Heuristics                            |" << endl;
    cout << "|                                Main Menu                               |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Two Optimal Heuristic                                       |" << endl;
    cout << "|  Option 2: Nearest Neighbour Heuristic                                 |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1: {
                Menu31();
            }
                break;
            case 2:{
                Menu32();
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

//Two Optimal Heuristic Menu

void Menu31(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                            Reading the Data                            |" << endl;
    cout << "|                         Two Optimal Heuristic                          |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Real-Word Graphs                                            |" << endl;
    cout << "|  Option 2: Toy Graphs                                                  |" << endl;
    cout << "|  Option 2: Extra Graphs                                                |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
            case 1:
                Menu311();
                break;
            case 2:
                Menu312();
                break;
            case 3:
                Menu333();
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

// Two Optimal Heuristic Extra Graph

void Menu333(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Extra Graphs                   |" << endl;
    cout << "|                          Two Optimal Heuristic                         |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Edges 25                                                    |" << endl;
    cout << "|  Option 2: Edges 50                                                    |" << endl;
    cout << "|  Option 3: Edges 75                                                    |" << endl;
    cout << "|  Option 4: Edges 100                                                   |" << endl;
    cout << "|  Option 5: Edges 200                                                   |" << endl;
    cout << "|  Option 6: Edges 300                                                   |" << endl;
    cout << "|  Option 7: Edges 400                                                   |" << endl;
    cout << "|  Option 8: Edges 500                                                   |" << endl;
    cout << "|  Option 9: Edges 600                                                   |" << endl;
    cout << "|  Option 10: Edges 700                                                  |" << endl;
    cout << "|  Option 11: Edges 800                                                  |" << endl;
    cout << "|  Option 12: Edges 900                                                  |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 12:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/EG/edges_25.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/EG/edges_50.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/EG/edges_75.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 4:
            {
                string filename = "../data/EG/edges_100.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 5:
            {
                string filename = "../data/EG/edges_200.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 6:
            {
                string filename = "../data/EG/edges_300.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 7:
            {
                string filename = "../data/EG/edges_400.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 8:
            {
                string filename = "../data/EG/edges_500.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 9:
            {
                string filename = "../data/EG/edges_600.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 10:
            {
                string filename = "../data/EG/edges_700.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 11:
            {
                string filename = "../data/EG/edges_800.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 12:
            {
                string filename = "../data/EG/edges_900.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

// Two Optimal Heuristic Real World Graph

void Menu311(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                    Reading the Data - Real-World Graphs                |" << endl;
    cout << "|                          Two Optimal Heuristic                         |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: GraphAM 1 (1k Nodes, 500 Edges)                             |" << endl;
    cout << "|  Option 2: GraphAM 2 (5k Nodes, 3M  Edges)                             |" << endl;
    cout << "|  Option 3: GraphAM 3 (10K Nodes, 10M Edges)                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1: {
                string filename = "../data/RWG/graph1/edges.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/RWG/graph2/edges.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/RWG/graph3/edges.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

//Two Optimal Heuristic Toy Graphs

void Menu312(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Toy Graphs                     |" << endl;
    cout << "|                         Two Optimal Heuristic                          |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Shipping                                                    |" << endl;
    cout << "|  Option 2: Stadiums                                                    |" << endl;
    cout << "|  Option 3: Tourism                                                     |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/TG/shipping.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 2: {

                string filename = "../data/TG/stadiums.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            case 3: {
                string filename = "../data/TG/tourism.csv";
                Algorithms::twoOptTSP(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }

}

// Nearest Neighbour Heuristic Real World Graph

void Menu321(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                    Reading the Data - Real-World Graphs                |" << endl;
    cout << "|                       Nearest Neighbour Heuristic                      |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: GraphAM 1 (1k Nodes, 500 Edges)                             |" << endl;
    cout << "|  Option 2: GraphAM 2 (5k Nodes, 3M  Edges)                             |" << endl;
    cout << "|  Option 3: GraphAM 3 (10K Nodes, 10M Edges)                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1: {
                string filename = "../data/RWG/graph1/edges.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/RWG/graph2/edges.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/RWG/graph3/edges.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

//Nearest Neighbour Heuristic Toy Graphs

void Menu322(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Toy Graphs                     |" << endl;
    cout << "|                       Nearest Neighbour Heuristic                      |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Shipping                                                    |" << endl;
    cout << "|  Option 2: Stadiums                                                    |" << endl;
    cout << "|  Option 3: Tourism                                                     |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/TG/shipping.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 2: {

                string filename = "../data/TG/stadiums.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 3: {
                string filename = "../data/TG/tourism.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }

}

//Nearest Neighbour Heuristic Menu

void Menu32(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                            Reading the Data                            |" << endl;
    cout << "|                       Nearest Neighbour Heuristic                      |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Real-Word Graphs                                            |" << endl;
    cout << "|  Option 2: Toy Graphs                                                  |" << endl;
    cout << "|  Option 3: Extra Graphs                                                |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
            case 1:
                Menu321();
                break;
            case 2:
                Menu322();
                break;
            case 3:
                Menu433();
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}


//Nearest Neighbour Heuristic Extra Graphs

void Menu433(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Extra Graphs                   |" << endl;
    cout << "|                        Nearest Neighbour Heuristic                     |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Edges 25                                                    |" << endl;
    cout << "|  Option 2: Edges 50                                                    |" << endl;
    cout << "|  Option 3: Edges 75                                                    |" << endl;
    cout << "|  Option 4: Edges 100                                                   |" << endl;
    cout << "|  Option 5: Edges 200                                                   |" << endl;
    cout << "|  Option 6: Edges 300                                                   |" << endl;
    cout << "|  Option 7: Edges 400                                                   |" << endl;
    cout << "|  Option 8: Edges 500                                                   |" << endl;
    cout << "|  Option 9: Edges 600                                                   |" << endl;
    cout << "|  Option 10: Edges 700                                                  |" << endl;
    cout << "|  Option 11: Edges 800                                                  |" << endl;
    cout << "|  Option 12: Edges 900                                                  |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 12:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/EG/edges_25.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 2:
            {
                string filename = "../data/EG/edges_50.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 3:
            {
                string filename = "../data/EG/edges_75.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 4:
            {
                string filename = "../data/EG/edges_100.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 5:
            {
                string filename = "../data/EG/edges_200.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 6:
            {
                string filename = "../data/EG/edges_300.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 7:
            {
                string filename = "../data/EG/edges_400.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 8:
            {
                string filename = "../data/EG/edges_500.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 9:
            {
                string filename = "../data/EG/edges_600.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 10:
            {
                string filename = "../data/EG/edges_700.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 11:
            {
                string filename = "../data/EG/edges_800.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            case 12:
            {
                string filename = "../data/EG/edges_900.csv";
                Algorithms::nearestNeighborTSP(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}





//About Menu


[[noreturn]] void Menu4(){

    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                  About                                 |" << endl;
    cout << "|                                Main Menu                               |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|  Program Done by:                                                      |" << endl;
    cout << "|  -Luis Filipe Pinto Cunha (up201709375@up.pt)                          |" << endl;
    cout << "|  -Ines Martin Soares (up202108852@up.pt)                               |" << endl;
    cout << "|  -Pedro Miguel Martins Romao (up202108660@up.pt)                       |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|    The goal of this assignment is twofold. First, implement a basic    |" << endl;
    cout << "|  exhaustive approach for the classic routing problem using the TSP     |" << endl;
    cout << "|  abstraction, therefore learning first hand that although such an      |" << endl;
    cout << "|  approach can find optimal solutions, its applicability is restricted  |" << endl;
    cout << "|  to very small graphs. Second, refine your critical thinking skills, by|" << endl;
    cout << "|  developing and analysing a set of approximate solutions to the TSP.   |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}
